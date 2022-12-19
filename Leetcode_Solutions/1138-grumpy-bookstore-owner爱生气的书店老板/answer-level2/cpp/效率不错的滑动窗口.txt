### 解题思路
滑动窗口，找出相比不使用技能最大满意人数的提升。

### 代码

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int max_improvement=0,improvement=0;
        int profit=0;
        int i;
        for(i=0;i<grumpy.size();i++){
            if(i<X){
                max_improvement+=grumpy[i]*customers[i];
            }
            profit+=(1-grumpy[i])*customers[i];
        }

        improvement=max_improvement;
        //cout<<"initial improvement: "<<improvement<<'\n';
        //cout<<"profit: "<<profit<<'\n';

        for(i=0;i<customers.size()-X;i++){
            improvement=improvement-grumpy[i]*customers[i]+grumpy[i+X]*customers[i+X];
            if(improvement>max_improvement){
                max_improvement=improvement;
            }
        }

        return profit+max_improvement;
    }
};
```