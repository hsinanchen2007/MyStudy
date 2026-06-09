### 解题思路
此处撰写解题思路
我的思路:
    一开始我总是想着找除最小的值，然后再最小的值的右边找出最大的值，然后相减，我的大脑也仅限于了题目的要求。思路还是不够
清晰，试过了几遍，再看看题目，最后我发现直接用从后往前后每一个相减的话，只要找出差值最大值就可以了，于是
我就从后往前实现了一遍，发现还真的是可以过掉的，最后返回的max有可能会是负数，所以判断了一下，是负数的话
就直接返回0嘛，加油哦各位！
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int max=-10000000;
        int len=0;
       for(int i=prices.length-1;i>=1;i--){
           for(int j=i-1;j>=0;j--){
               len=prices[i]-prices[j];
               if(len > max){
                   max=len;
               }
           }
       }
        if(max <=0){
            return 0;
        }
        return max;
    }
}
```