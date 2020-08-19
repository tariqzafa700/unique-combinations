/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
using namespace std;

bool haveCommonChars(string &first, string &sec)
{
  unordered_map<char, int> smap;
  for (auto ch : first)
  {
    if (smap[ch] == 1)
    {
      return true;
    }
    smap[ch]++;
  }
  for (auto ch : sec)
  {
    if (smap[ch] == 1)
    {
      return true;
    }
    smap[ch]++;
  }
  return false;
}

void getCombo(vector<string> &strs, string init, int start,
              vector<string> &all)
{
  for (int i = start; i < strs.size(); ++i)
  {
    if (!haveCommonChars(init, strs[i])) //Remove this check to find all combinations
    {
      all.push_back(init + strs[i]);
      getCombo(strs, init + strs[i], i + 1, all);
    }
  }
}

int getMaximumCombination(vector<string> &strs)
{
  string init = "";
  vector<string> all;

  getCombo(strs, init, 0, all);
  for (auto &a : all)
  {
    cout << a << endl;
  }
  int maxCount = 0;
  for (auto &a : all)
  {
    if (maxCount < a.size())
    {
      maxCount = a.size();
    }
  }

  return maxCount;
}

int main()
{
  vector<string> strs =
      {
          "un", "iq", "ue"};
  cout << getMaximumCombination(strs) << endl;

  /*strs =
     {
     "ab", "ba", "cd", "dc", "ef", "fe", "gh", "hg"};
     cout << getMaximumCombination (strs) << endl; */
  return 0;
}
