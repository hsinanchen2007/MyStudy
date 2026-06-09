### 解题思路
时间靠前的答案的确很快，但是普适性差了些，以下代码可以更改要匹配的string s，ti[i]/si[i]即有多少组ti[i]可以用来组成单词

### 代码

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
		 string s="balloon";
		 vector<int> si(26,0),ti(26,0);
		 for(char it:s) ++si[it-'a'];
		 for(char it:text) ++ti[it-'a'];
		 int res=text.length();
		 for(int i=0;i<26;++i)
			 if(si[i]!=0&&ti[i]/si[i]<res) res=ti[i]/si[i];
		 return res;
    }
};
```