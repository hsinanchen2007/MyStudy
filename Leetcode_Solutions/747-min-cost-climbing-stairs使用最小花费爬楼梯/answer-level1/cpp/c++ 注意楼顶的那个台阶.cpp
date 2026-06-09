```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost.push_back(0); //因为要到楼顶，所以最后一层台阶可以不踩，所以在cost最后加上一个花费为0的台阶 代表楼顶
        // vector<int> minCost(cost.size()+1,0);
        // minCost[0]=0;
        // minCost[1]=cost[0];
        // for(int i=2;i<=cost.size();i++){
        //     minCost[i]=min(minCost[i-1]+cost[i-1],minCost[i-2]+cost[i-1]);
        //     // cout<<minCost[i]<<endl;
        // }
        // return minCost[cost.size()];
        
        //优化
        cost.push_back(0);
        int prepre=0;
        int pre=cost[0];
        for(int i=2;i<=cost.size();i++){
            int temp=min(pre+cost[i-1],prepre+cost[i-1]);
            prepre=pre;
            pre=temp;
        }
        return pre;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4413273b8fcb4d9a1bec77e76352f1cfdf35e9f8c17de3b5f629d66f1260051c-image.png)
