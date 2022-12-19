#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Solution {
public:
    int calculateTime(string keyboard, string word) {
    	int n1 = 0;
 int n2 = 0;
 int i = 0;
 int j = 0;
 int s = 0;
 for(i=0;i<word.size();i++)
 {
 for(j=0;j<keyboard.size();j++)
 {
  if(word[i]==keyboard[j])
  {
  	n2 = j;
  	s = abs(n2-n1)+s;
  	n1 = n2;
  	break;
  }
 }
 }  
    return s;	
        
    }
        
};