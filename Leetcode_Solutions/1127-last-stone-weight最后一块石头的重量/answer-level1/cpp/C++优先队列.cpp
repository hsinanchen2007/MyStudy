### 解题思路
好像也不快……

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int n:stones)pq.push(n);
        while(pq.size()>=2){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b)
            pq.push(a-b);
        }
        if(pq.empty())return 0;
        else return pq.top();
    }
};
```