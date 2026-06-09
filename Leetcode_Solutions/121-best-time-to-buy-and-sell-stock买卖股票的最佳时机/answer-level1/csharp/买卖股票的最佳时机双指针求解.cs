### 解题思路
利用双指针 一次遍历求解
![QQ截图20200205022324.jpg](https://pic.leetcode-cn.com/ceaf24573d9376dd30bbf6e0086d684aa9c4b2be96fc208c20c22130201aba4c-QQ%E6%88%AA%E5%9B%BE20200205022324.jpg)


### 代码

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        int index_l=0,index_r=1,max=0;
        while(index_r<prices.Count()){
            if(prices[index_r]-prices[index_l]>=0)
            {
                if(prices[index_r]-prices[index_l]>max)
                    max=prices[index_r]-prices[index_l];
                index_r++;
            }
            else if(prices[index_r]-prices[index_l]<0){
                index_l=index_r;
                index_r++;
            }
        }
        return max;
    }
}
```