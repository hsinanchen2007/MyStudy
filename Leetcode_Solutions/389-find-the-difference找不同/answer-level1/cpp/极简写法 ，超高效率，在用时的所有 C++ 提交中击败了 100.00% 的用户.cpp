### 解题思路
可以使用num[26]存储每个字符的出现次数；
s中出现的字符统计一次，存在nums中；
t中出现的字符统计一次，也存在nums中；
可以发现s和t中相同的部分都统计过偶数次，那么不同的字符就是奇数次；
这样mod2就可以找到不同的字符。

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int nums[26]={0};
    
        for(int i=0;i<s.size();i++)
        {
            nums[s[i] - 'a']++;
        }
        
        for(int i=0;i<t.size();i++)
        {
            nums[t[i] - 'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(nums[t[i] - 'a']%2==1)
                return t[i];
        }
        return -1;
    }
};
```