**思路**：
依次遍历数组，迭代当前值<栈顶，则依次将栈顶小于当前值数值出栈，否则入栈，
当栈大小==1时，记为bottom，
当栈大小>2时，获取top-bottom，并计算到目前为止的最小值。

![image.png](https://pic.leetcode-cn.com/7d07076f358cee655f881ff06c4c98a5512a654e2b0629e6c7bbc6b9ba29f6ca-image.png)

时间复杂度还不错，毕竟只用遍历一次数组；
空间复杂度勉强吧



```cpp []
    int maxProfit(vector<int>& prices) {
        // 方法2: 使用栈
        stack<int> stackStock;
        int max = 0;
        int bottom = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(stackStock.size() == 0 || stackStock.top() <= prices[i])
                stackStock.push(prices[i]);
            else if(stackStock.top() > prices[i])
            {
                while(stackStock.size()>0 && stackStock.top() > prices[i])
                    stackStock.pop();
                stackStock.push(prices[i]);
            }
            if(stackStock.size() == 1)
                bottom = stackStock.top();

            if(stackStock.size() >= 2)
            {
                if(stackStock.top() - bottom > max)
                    max = stackStock.top() - bottom;
                if(stackStock.top() - bottom == 0)
                {
                    while(stackStock.size() != 1)
                        stackStock.pop();
                }
            }
        }
        return max;
    }
```
