# LeetCode 451.根据字符出现频率排序

## 题目：

给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

## 思想：

我的想法是使用map或者unordered_map进行频率统计，因为在c++中是map底层实现是红黑树，unordered_map底层实现是哈希表，所以无法直接输出答案。故采用优先级队列priority_queue对统计结果进行处理，最后进行字符串的拼接即可。

## 代码:

```cpp
class Solution {
public:
    string frequencySort(string s) {
        using pair = pair<char, int>;
        unordered_map<char, int> hash;
        auto cmp = [](pair a, pair b) { return a.second < b.second; }; //定义优先级队列的排序规则，使用匿名函数进行
        priority_queue<pair, vector<pair>, decltype(cmp)> pq(cmp);
        for(auto c: s) { hash[c] += 1; }
        //将哈希表中的元素按照排序规则放入队列中
        for(auto it = hash.begin(); it != hash.end(); ++it){
            pair temp = make_pair(it->first, it->second);
            pq.push(temp);
        }
        string res;
        while(!pq.empty()){
            auto it = pq.top();
            while(it.second--) { res += it.first; }
            pq.pop();
        }
        return res;
    }
};
```
![leetcode题解.png](https://pic.leetcode-cn.com/440d4db79f1b3379b1ce1f9e6266da986eaf3f38e779ab3aefa83305b0a1bf6a-leetcode%E9%A2%98%E8%A7%A3.png)
