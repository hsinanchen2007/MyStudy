#### 方法一：暴力搜索
使用递归算法，每次将当前价格与后面的价格比较，如果后面价格比当前价格高，则用差价+递归后面的部分，得到本次循环最大值，所有遍历结果求最大值得到最佳收益。时间复杂度O(n^n)，调用递归函数n^n次；空间复杂度O(n)，递归的深度为n。**该方法超出时间限制**
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return calculate(prices, 0);
    }

public:
    int calculate(vector<int>& prices, int s){
        if(s>=prices.size())
            return 0;
        int max=0;
        for(int start=s; start<prices.size(); start++){
            int maxprofit=0;
            for(int i=start+1; i<prices.size(); i++){
                if(prices[start]<prices[i]){
                    int profit=calculate(prices, i+1)+(prices[i]-prices[start]);
                    if(profit>maxprofit)
                        maxprofit=profit;
                }
            }
            if(maxprofit>max)
                max=maxprofit;
        }
        return max;
    }
};
```

#### 方法二：贪心算法
![image.png](https://pic.leetcode-cn.com/d225c4178aa427a4e3757190618e6eed5bbfeab9090d2f06f34002bbc87fa3e6-image.png)
![image.png](https://pic.leetcode-cn.com/98543fc7a5424f34abcb4ff1a44cc3ee6c815a92a1dbc8f45f38d1748f639d8a-image.png)

不限次数，相当于累加多个波谷-波峰的差值，对于(a,b,c,d), 若b>a, b>c, d>c，即两个波谷a,c；两个波峰b,d，则(d-a)<(b-a)+(d-c),C总是小于A+B。基于这样的原则，只需每两个位置之间计算一次差值，将多次正的差值相加便是最终的结果。时间复杂度O(n)，只需遍历一次；空间复杂度O(1)，需要常量的空间。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-prices[i-1];
            if(diff>0)
                maxprofit+=diff;
        }
        return maxprofit;
    }
};
```

