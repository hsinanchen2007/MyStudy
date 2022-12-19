### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        int hash[100][1];//hash[int(某个字符)][0]存这个字符的下标

        for(int i=0;i<100;i++)
            hash[i][0]=-1;
        int left=0,right=0,maxs=0;

        for(;right<s.size();right++)
        {
            
            if(hash[int(s[right])%97][0]==-1||hash[int(s[right])%97][0]<left)
            {
                hash[int(s[right])%97][0]=right;
                maxs=max(maxs,right-left+1);
                continue;
            }
            else {
                left=hash[int(s[right])%97][0]+1;//left移到上次出现这个字符的下一个字符所在位置
                hash[int(s[right])%97][0]=right;//更新hash
            }
        }
        return maxs;
    }
};
```