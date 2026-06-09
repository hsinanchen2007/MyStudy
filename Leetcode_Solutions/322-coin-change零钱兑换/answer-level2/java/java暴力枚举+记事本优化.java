### 解题思路
没啥好说的，就是个二叉树暴力枚举,细节都在注释里写明白了

### 代码

```java
class Solution {
public int coinChange(int[] coins, int amount) {
        /*之所以记事本用amount个长度的数组，请考虑如下输入情况amount =100;coins=[1]，每一层递归都产生一个新的参考值,100个长度刚够*/
        return coinChange(coins,amount,new int[amount+1]);
    }
    public int coinChange(int[] coins, int amount,int[]book) {
        int min = Integer.MAX_VALUE;
        /*最后一层，当amout<0说明此路不通，返回-1，min值不改变*/
        if(amount<0){
            return -1;
        }
        /*最后一层，当此路通，返回0，上一层min值改变*/
        if (amount==0){
            return  0 ;
        }
        /*中间层：当记事本中已经有这个剩余值的最短路径，不再计算，直接返回*/
        if(book[amount]!=0){
            return book[amount];
        }
        for (int i = 0; i <coins.length ; i++) {
            /*中间层：穷举遍历所有路径，得到所有子路径的长度返回值，用if判断取其最小值*/
         int res =  coinChange(coins,amount-coins[i],book);
         /*判断条件：过滤掉走不通的-1值和res>原min的更长路径*/
            if(res>=0&&min>res){
                /*逆向返回路径长度*/
                min = res +1 ;
            }
        }
        book[amount] = min;
        return  min==Integer.MAX_VALUE?-1:min ;
    }
}
```