## 问题描述
有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。

假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。

 

给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。

你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。

请返回待替换子串的最小可能长度。

如果原字符串自身就是一个平衡字符串，则返回 0。

![](https://pic.leetcode-cn.com/42ee5e383b9daf65e852a0b7477069e0dd877a7a1135cf20bb6897aa27f39937.png)

[替换子串得到平衡字符串](https://leetcode-cn.com/problems/replace-the-substring-for-balanced-string/ "替换子串得到平衡字符串")


## 解决方法
### 滑动窗口

可以参考这篇文章[https://liyiping.cn/article/permutation-in-string/](https://liyiping.cn/article/permutation-in-string/ "https://liyiping.cn/article/permutation-in-string/")

- 先将多余平均数的字符找出来，用need数组记录下来，因为多余的字符必然要换成别的

- 接下来就是滑动窗口不断扩大寻找最小值了，参考上边的文章中说到的滑动窗口通用思想即可


```cpp
class Solution {
public:
    int balancedString(string s) {
        int size=s.size();
        int avg=size/4;
        int left=0,right=0,match=0,res=INT_MAX;
        unordered_map<char,int>m,need,window;
        for(auto i:s){
            m[i]++;
        }
        for(auto item:m){
            if(item.second>avg){
                need[item.first]=item.second-avg;
            }
        }
        if(need.size()==0)return 0;
        while(right<size){
            if(need.count(s[right])){
                window[s[right]]++;
                if(window[s[right]]== need[s[right]]){
                    match++;
                }
            }
            right++;
            while(match==need.size()){
                res=min(right-left,res);
                if(need.count(s[left])){
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]])match--;
                }
                left++;
            }

        }

        return res;
    }
};
```

my site: [https://liyiping.cn](https://liyiping.cn)