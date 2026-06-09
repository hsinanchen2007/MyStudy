### 解题思路
采用双重循环，没有任何技巧性的暴力求解。外层指针min用来找到极小值，内层指针max用来找到极大值。
### 知识点
无
### 感悟
自己在最初编译的时候有很多细节点没有注意到，说明码代码的量还是太少。
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //本题的思路是：在最低点的时候买入股票，在最高点的时候卖出股票。
        if(size(prices)==0)return 0;//细节点1：需要考虑数组为0时的情况
        int min,max;
        int i=0,j=0;
        int profit=0;
        for(i=0;i<size(prices)-1;){
            //外层循环，用来发现极小值
            if(prices[i]<prices[i+1]){
                min=prices[i];
                //内层循环，用来发现极大值
                for(j=i+1;j<size(prices);j++){
                    //当极大值出现在数组中间时
                    if(prices[j]<prices[j-1]){
                        max=prices[j-1];
                        break;//细节点2：在找到极大值后应直接跳出内循环
                    }
                    //当极大值出现在数组末端时
                    if(j==size(prices)-1&&prices[j-1]<=prices[j]){//细节点3：符号应为<=，因为需考虑到测试用例（1,5,9,9,9）
                        max=prices[j];
                        break;
                    }
                }
                profit+=max-min;
                i=j-1;
                if(j==size(prices)-1)
                    break;
            }
            else
                i++;
        }
        return profit;
    }
};
```