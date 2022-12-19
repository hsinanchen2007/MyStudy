### 解题思路
此处撰写解题思路

### 代码

```cpp
#include<cmath>
class Solution {
public:
    string longestPalindrome(string s) {
    	if(s.size()<=1)return s;
       int n=s.size(),s_start=0;
       int start=0,end=0,i=0,len=0;
      
       	while(i<n){
       		start=i,end=i;
       		while(end+1<n&&s[end]==s[end+1])end++;
       		i=end+1;
       		while(start-1>=0&&end+1<n&&s[start-1]==s[end+1]){
       			start--;
       			end++;
       		}
       	if(end-start+1>len){
       		len=end-start+1;
            s_start=start;
       	}

       	}
       return s.substr(s_start,len);
    }
};
```