实际上只需要比较数组中相邻元素的差值，只要是正值即为利润，负值则不予考虑，求和即可得到最终解。

![屏幕快照 2020-04-10 09.58.51.png](https://pic.leetcode-cn.com/8260b664da1813d94619b0644f291758a602ded5b4d433577dbf26e466be3b89-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-10%2009.58.51.png)
****

代码如下：

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size<=1) return 0;
        int profit = 0, delta=0;
        for(int i=1; i<size; i++){
            delta = prices[i]-prices[i-1];
            if(delta>0) profit+=delta;
        }
        return profit;
    }
};
```
