### 解题思路
超简单的思路
首先统计字符总数，同时记录字符个数是奇数的出现次数
例如'aaabbd'字符总数是6，奇数次数是2（a和d）
我们发现，一个回文字符串最多只能保留一个奇数，那么其它奇数都要-1变成偶数
一共有odd个奇数，那么我们对于最长的回文字符串，就要减去(odd-1)个1，把其余的奇数都变成偶数，只保留一个奇数
假如odd=0，那么就不用减了，全部是偶数的字符一定能构成回文串


![image.png](https://pic.leetcode-cn.com/ba0a67c0a6f46aa0db600a3e56425e1caee18220d38841a1df6b093796a482e6-image.png)


### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int mp[52]={0};
        for(char ch:s){
            if(ch<='z'&&ch>='a')
                mp[ch-'a']++;
            else
                mp[ch-'A'+26]++;
        }
        int ans=0;
        int odd=0;
        for(int i=0;i<52;i++){
            ans+=mp[i];
            if(mp[i]%2!=0)
                odd++;
        }
        if(odd!=0) ans-=odd-1;
        return ans;
    }
};
```