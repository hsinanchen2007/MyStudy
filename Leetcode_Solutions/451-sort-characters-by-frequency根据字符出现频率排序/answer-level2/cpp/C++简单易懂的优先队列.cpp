
这个方法运行效率如下：
![image.png](https://pic.leetcode-cn.com/f7bf9550c7dd9410cf829c07325f29467706cd11731691ac45e74b04281c2585-image.png)

先用一个map来统计了字符频率
然后使用优先队列（大根堆），优先级函数使用自定义函数
直到大根堆弹空为止，用res搜集答案
这里需要注意的是，自定义函数中，左小于右为大根堆
```
class Solution {
public:
    string frequencySort(string s) {
        string res="";
        unordered_map<char, int> m;
        // 用map搜集字符出现次数
        for(char c: s)
            m[c]++;
        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> q;
        for(pair<char,int> p: m)   // 建堆
            q.push(p);
        while(q.empty() == false){    // 搜集答案
            pair<char,int> t = q.top();
            res.insert(res.end(), t.second, t.first);
            q.pop();
        }
        return res;
    }
    // 自定义优先级函数
    struct cmp{
        bool operator() (const pair<char,int> &a, const pair<char,int> &b){
            return a.second < b.second;
        }
    };
};
```