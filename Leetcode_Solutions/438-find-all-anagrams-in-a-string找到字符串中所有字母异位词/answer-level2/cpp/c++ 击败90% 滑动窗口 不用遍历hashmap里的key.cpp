### 解题思路
思路是比较简单的，用一个hashmap记录目标串每个字符出现的次数。
因为子串是字母异位词，所以目标子串的长度一定和p是一样的。我们可以用滑动窗口的思想来处理这个问题。在我刚开始写的时候其实是计划使用第二个hashmap去存储窗口内子串的字符分布的。
这姑娘是开始写的时候意识到其实没有必要，并且那样要比较两者分布是否一致可能还要遍历26个字母或者某个hashmap里的key，这样虽然复杂度是一样的，但耗时会增加几倍。

我们其实可以在滑动窗口的过程中直接对第一个hashmap进行操作，新增的字符（窗口尾部下一个字符）我们把hashmap数量-1，去掉的字符（窗口头部字符）我们把hashmap数量+1。 
但这样的话我们还是要遍历一遍hashmap 去验证是否每一项都为0，还是要遍历一遍hashmap。 有没有更优的解法呢？

我们用一个数字记录字符串出现次数不够的字符总数即可，即所有满足hashmap[key]>0的value的和。更新的时候只要考虑一下++或者--操作时，这个数字是否为正，为正的话就要把这个字符总数对应++或者--，稍微注意一下边界条件即可。 具体参见代码。

![image.png](https://pic.leetcode-cn.com/90f756a80b382ff6d6830ca8c1cd8c4c9c5d4bc305b6f81e3a8c6f2557deac6c-image.png)

[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题，真诚欢迎大家star和follow 最近也在学习和实现lua，欢迎交流


### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cp;
        vector<int> ans;
        int sum = 0;

        for (auto c: p) {
            cp[c]++;
            sum++;
        }

        if (s.size() < p.size()) return ans;

        int start = 0;
        int end = 0;

        for (end = 0; end < p.size(); end++) {
            if (cp[s[end]] > 0) {
                sum--;
            }
            cp[s[end]]--;
        }
        if (sum == 0) ans.push_back(0);
        
        end = p.size() - 1;
        while(end+1 < s.size()) {
            end++;
            if (cp[s[start]]>=0) {
                sum++;
            }
            cp[s[start]]++;
            if (cp[s[end]]>0) {
                sum--;
            }
            cp[s[end]]--;
            start++;
            if (sum == 0) ans.push_back(start);
        }

        return ans;
    }
};
```