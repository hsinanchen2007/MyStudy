### 解题思路
使用vector<int> si(26,0);统计各个字母出现次数
使用双指针，i作为快指针，j作为慢指针，当res和s[i]相同时，res不满足条件，使用j遍历下一个字母是否满足条件
j==i代表j到i之间没有满足条件的字母

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
		vector<int> si(26,0);
		int j=0,len=s.size();
		char res=' ';
		for(int i=0;i<len;++i){
			++si[s[i]-'a'];
			if(s[i]==res){
				while(j<i&&si[s[j]-'a']!=1) ++j;
				if(j==i) res=' ';
				else res=s[j];
			}else if(si[s[i]-'a']==1&&res==' ')
				res=s[i];			
		}
		return res;
    }
};
```