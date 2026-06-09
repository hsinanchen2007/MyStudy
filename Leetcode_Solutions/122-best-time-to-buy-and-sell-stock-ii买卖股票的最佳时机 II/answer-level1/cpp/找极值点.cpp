### 解题思路
萌新猜是不是和极值有关，试了下处理完边界就过了。
有个细节就是极小值左边不取等号，极大值右边不取等号（防止双花现象）

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0,len=prices.size();
        if(len<=1)
        return 0;
        if(prices[0]<=prices[1])
        sum-=prices[0];
        for(int i=1;i<prices.size()-1;i++){
            if(prices[i]>prices[i+1]&&prices[i]>=prices[i-1]){
                sum+=prices[i];
            }
            else if((prices[i]<=prices[i+1]&&prices[i]<prices[i-1])){
                sum-=prices[i];
            }
            else{
                continue;
            }
        
        }
        if(prices[len-1]>=prices[len-2])
        sum+=prices[len-1];
        //if(sum<0) sum=0;
        return sum;
    }
};
```