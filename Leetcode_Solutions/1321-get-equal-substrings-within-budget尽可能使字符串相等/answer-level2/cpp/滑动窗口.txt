## 问题描述
给你两个长度相同的字符串，s 和 t。

将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。

![](https://pic.leetcode-cn.com/45fd782a3fbbf5e1749e8acada9c197f2065be0374073278e3d6fe906b42b4d4.png)

[尽可能使字符串相等](https://leetcode-cn.com/problems/get-equal-substrings-within-budget/ "尽可能使字符串相等")

## 解决方法
### 滑动窗口

- right指针不断右移，用cost记录当前窗口内变换所需要的开销，时刻更新返回值

- 当前cost大于maxCost时，移动left指针，直至不符合条件

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int right=0,left=right,size=s.size();
        int cost=0,res=0;
        while(right<size){
            if(cost<=maxCost){
                cost+=abs(s[right]-t[right]);
                res=max(res,right-left);
            }
            right++;
            while(cost>maxCost){
                cost-=abs(s[left]-t[left]);
                left++;
            }
            if(cost<=maxCost)res=max(res,right-left);
        }
        return res;
    }
};
```

my site: [https://liyiping.cn](https://liyiping.cn)