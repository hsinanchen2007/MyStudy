### 解题思路
开始看到这个题还想用把数组排序，然后从最前以及最后两个数判断它们在原数组的位置关系是否一前一后结果不可行因为有可能有重复元素。。。涉及到查了些函数
 vector<int>::iterator iN=find(prices.begin(),prices.end(),sortPrices[i]);
 vector<int>::iterator out=find(prices.begin(),prices.end(),sortPrices[j]);
                if(iN<out) return sortPrices[j]-sortPrices[i];

看了题解一遍排序即可
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int minPrice=prices[0];
        int max=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minPrice) minPrice=prices[i];
            if(prices[i]-minPrice>max) max=prices[i]-minPrice;
        }
        return max;
    }
};
```