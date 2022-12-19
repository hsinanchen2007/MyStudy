### 解题思路
第一种暴力求解很简单，不多说了。

关于第二种方法，官方题解中给出的解释是有问题的，但是代码是没有问题的，注意代码中
```
ans=max(ans,prices[i]-minPrice);
```
这一行，以评论中[2,5,1,3]为例，当minPrice更新为最小值1时，price[3]-minPrice=2（=3-1）。
此时ans为3（=5-2），不更新ans值，所以答案是没错的。

但是怎么理解还没想到好的解释，等以后想到再更新吧。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=1e9;
        int ans=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            ans=max(ans,prices[i]-minPrice);
            minPrice=min(minPrice,prices[i]);
        }
        return ans;
    }
};
```