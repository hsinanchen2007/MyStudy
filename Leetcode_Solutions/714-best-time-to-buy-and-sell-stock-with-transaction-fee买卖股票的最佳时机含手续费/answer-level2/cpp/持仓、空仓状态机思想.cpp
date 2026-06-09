算法思路：1）状态判断：首先根据题目特点容易知道要么持仓，要么空仓，持仓时只能等待卖出，空仓时只能等待买入；两个状态对立，可设置一个状态标记变量flag，当flag=0时，表示处于空仓待买入状态，flag=1时表示处于持仓待卖出状态。2）空仓状态下的行为：空仓状态下的关键任务或者行为是如何寻找买入点，显然当前prices[i]减去当前的最低点min后比交易成本大，说明买入是必然有利可图的，所以这是空仓状态下买入的唯一条件；另外min要时刻保持当前状态下的最低点，所以必须在prices[i]<min的条件下及时更新。3）持仓状态下的行为：持仓状态下的关键任务或者行为是如何寻找卖出点，显然当前卖出点s比prices[i]还大fee，说明在s处卖出可以获利，而且不影响后面的买入获利机会；另外在f未达到卖出条件时，要时刻保持当前卖出点s的更新，当prices[i]>s时，要更新。

```
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int k=prices.size();
        if(k<2){
            return 0;
        }
        
        int sum=0;//当前利润
        int min=prices[0];//当前最低值
        int b;//记录买入点
        int s;//记录当前卖出点
        int flag=0;//状态标记，=1为当前处于持仓状态，待卖出；=0当前处于空仓状态，待买入
        for(int i=1;i<k;i++){//遍历prices数组
            if(!flag){//空仓状态：此状态下要寻找买入点或者更新最低点或者不作任何变化
                if(prices[i]-min>fee){//买入条件
                    flag=1;
                    b=min;
                    s=prices[i];
                    continue;//这一句不要漏掉
                }
                else if(prices[i]<min){//更新最低点条件
                    min=prices[i];
                }
            }
            if(flag){//持仓状态：此状态下要寻找卖出点或者更新卖出点或者不作任何变化
                if(s-prices[i]>fee){//卖出条件
                    flag=0;
                    sum+=s-b-fee;
                    min=prices[i];
                }
                else if(prices[i]>s){//更新卖出点条件
                    s=prices[i];
                }
            }
        }
        if(flag){
            sum+=s-b-fee;
        }
        return sum;
    }
};
```

运行结果：在一次提交中 105ms,92.20%;15MB,90.59%
