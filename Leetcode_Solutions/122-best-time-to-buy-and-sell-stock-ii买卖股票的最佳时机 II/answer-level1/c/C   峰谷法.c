### 解题思路
思路和官方法2一样，实现起来比官方复杂点，但用时快了很多，记录一下
![捕获.JPG](https://pic.leetcode-cn.com/400c96d02b4a5a8441c256ca3af4f99bc986269e9663296a62c99a45895b8457-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int i=0,j=1,min=0,max=0;
    int result=0;
    for(;i < pricesSize && j < pricesSize;i++,j++){
        while(prices[i]>prices[j] && j < pricesSize){
            i++;
            j++;
            if(j==pricesSize)
                return result;
        }
        min=prices[i];
        while(prices[i]<prices[j] && j < pricesSize){
            i++;
            j++;
            if(j==pricesSize)
                break;
        }
        max=prices[i];
        result=result+max-min;
    }
    return result;
}
```