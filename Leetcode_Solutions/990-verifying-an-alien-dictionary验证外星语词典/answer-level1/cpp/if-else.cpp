### 解题思路


![image.png](https://pic.leetcode-cn.com/9e6d7eb6b5d7aaff4cb123a7b39af7e7e7efb3c5da9a819183cbfdc0b6024200-image.png)


### 代码

```cpp
class Solution {
public:
	int find(char c,string &s){
		for(int i=0;i<s.size();i++)
			if(c==s[i])
				return i;
		return 0;
	}
	
    bool isAlienSorted(vector<string>& words, string order) {
        int pre,now;
        int i,j;
		for(i=0;i<words.size()-1;i++){
			j=0;
			while(j<words[i].size()&&j<words[i+1].size()){
				pre=find(words[i][j],order);
				now=find(words[i+1][j],order);
				if(pre>now)
					return 0;
				else if(pre<now)
					break;
				j++; 
			}
			if(j<words[i].size()&&j<words[i+1].size())
				continue;
			else if(j<words[i].size())//前几个字母相同，长度不同 
				return 0;
		}
		return 1; 
    }
};
```