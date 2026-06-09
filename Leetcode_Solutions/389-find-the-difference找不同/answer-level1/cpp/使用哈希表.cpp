### 解题思路
纯新手，C++刚学不久，不知道leetcode能不能存笔记，写个题解当做笔记。

把t中字母的出现次数保存在散列表中，s中字母的出现次数减掉，随机添加的字母最终为1，其他字母为0。

遍历散列表，累加得到对应字母的ASCII码，最后输出。（此处应该有更好的办法）

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int r=0;
        int hash[26]={0};
        
        for(char n:t)
        hash[n-'a']++;
        for(char n:s)
        hash[n-'a']--;

        for(int i=0;i<26;i++){
            if(hash[i]==0)
            r+=1;
            else
            return char('a'+r);
        }
        return -1;
    }
};
```