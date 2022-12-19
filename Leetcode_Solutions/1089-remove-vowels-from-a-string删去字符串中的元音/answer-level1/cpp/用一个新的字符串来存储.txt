#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string removeVowels(string S) {
    	 int i = 0;
    	 string s1;
 for(i=0;i<S.size();i++)
 {
  if((S[i]!='a')&(S[i]!='e')&(S[i]!='i')&(S[i]!='o')&(S[i]!='u'))
  {
   s1.append(1,S[i]);
  }
 }
 return s1; 
    }
};