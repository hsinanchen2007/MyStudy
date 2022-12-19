### 解题思路
1.先将vector中的数据放入优先队列（大顶堆），优先队列自动排序。
2.按照题目从优先队列中取数据，作比较
3.如果优先队列中还有1个元素，则返回；否则返回0.

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int,vector<int>,less<int> >q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }
        int x,y;
        while(q.size()>1){
            x=q.top();
            q.pop();
            y=q.top();
            q.pop();
            if(x==y){
                continue;
            }else{
                x<y?q.push(y-x):q.push(x-y);
            }
        }
        if(q.size()==1){
            return q.top();
        }else{
            return 0;
        }
    }
};
```