具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/1046.last_stone_weight)  

```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        priority_queue<int> tmp(stones.begin(),stones.end());
        while(tmp.size()>1)
        {
            int max=tmp.top();
            tmp.pop();
            int sec=tmp.top();
            tmp.pop();
            int res=max-sec;
            tmp.push(res);
        }
        return tmp.top();
    }
};
```

> 执行用时 : 8 ms, 在Last Stone Weight的C++提交中击败了42.50% 的用户  
内存消耗 : 8.5 MB, 在Last Stone Weight的C++提交中击败了100.00% 的用户