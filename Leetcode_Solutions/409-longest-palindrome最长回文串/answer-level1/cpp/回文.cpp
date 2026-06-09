### 解题思路
此处撰写解题思路

### 代码

```cpp
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s1) {
           	int aa[30]={0};
	int bb[30]={0};
	//string s1;
	//cin>>s1;
 	for(int i=0;i<s1.length();i++)
 	{
 		if(s1[i]>='a'&&s1[i]<='z')
 		aa[(int)s1[i]-96]++;
 		if(s1[i]>='A'&&s1[i]<='Z')
 		bb[(int)s1[i]-64]++;
	 }
	 
	 int sum=0;
	 for(int i=1;i<=26;i++)
	 {
	 	if(aa[i]%2==1||bb[i]%2==1)
	 	{
	 		sum++;
	 		break;
		 }
	 }
	  for(int i=1;i<=26;i++)
	  {
	  	if(aa[i]%2==0)
		sum=sum+(aa[i]);
		if(bb[i]%2==0)
		sum=sum+(bb[i]);
		if(aa[i]%2!=0&&aa[i]>1)
         sum=sum+(aa[i]-1); 
         if(bb[i]%2!=0&&bb[i]>1)
         sum=sum+(bb[i]-1); 
	  }
	  //cout<<sum; 
      return sum;
    }
};
```