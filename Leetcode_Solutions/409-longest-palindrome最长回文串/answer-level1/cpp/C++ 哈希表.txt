思路特别简单：统计每个数出现的次数。若是偶数，直接相加，若是奇数，减一相加。最后判断是否等于字符串长度，若不等于，则可以随意取一个字符作为中间字符。
代码如下：
```
class Solution {
public:
    int longestPalindrome(string s) {
    	unordered_map<char,int> mymap;
    	int res=0;
    	for(int i=0;i<s.length();i++)
    		mymap[s[i]]++;
    	for(auto it=mymap.begin();it!=mymap.end();it++){
    		res += it->second-(it->second)%2;
    	}
    	return s.length()-res==0 ? res:res+1;
    }
};
```
