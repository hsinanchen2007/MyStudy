### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> midd(gas.size());
        int i;int sum=0;
        for( i=0;i<gas.size();i++){
            midd[i]=gas[i]-cost[i];
        }
           int left=0,right=(left+1)%midd.size();
           sum=sum+midd[left];
           while(left<midd.size()&&left!=right){
               
               while(sum<0&&left<midd.size()){
                   sum=sum-midd[left];
                   left=left+1;
                   if(left>=right&&left<midd.size()){
                       sum=sum+midd[left];
                       right=(left+1)%midd.size();
                   }
                   
                   
               }
               sum=sum+midd[right];
               
                   right=(right+1)%midd.size();
                   
               
           }
           if(sum<0||left==midd.size())
           return -1;
           else return left;
        
    }
};
```