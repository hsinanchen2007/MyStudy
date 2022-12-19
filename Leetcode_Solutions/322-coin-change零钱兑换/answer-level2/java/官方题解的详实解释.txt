### 解题思路


### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        //  if(amount<1)
          return coinChange(coins,amount,new int[amount]);        
    }
    //coins 硬币面值
    //rem 总值
    //count[] 记录的信息
    private int coinChange(int [] coins,int rem,int [] count){
            if(rem==0) return 0;//解决输入不合理
            if(rem<0)return -1;//解决输入合理
            if(count[rem-1]!=0){return count[rem-1];}//如果以前已经有了记录,就返回被记录的数值
            int min=Integer.MAX_VALUE;
            for(int i=0;i<coins.length;i++){
                int res=coinChange(coins,rem-coins[i],count);//递归,如果以前有了相关的内容会直接反回
                //如果是最小的,那么就加1,作为最少币数
                if(res>=0&&min>res){
                    min=res+1;
                }
            }
            //min有没有被改变,要是改变了就不会是原值,自然回min
            count[rem - 1] = (min == Integer.MAX_VALUE) ? -1 : min;
            return count[rem - 1];
    }
}

```



































// public class Solution {

//   public int coinChange(int[] coins, int amount) {
//     if (amount < 1) return 0;
//     return coinChange(coins, amount, new int[amount]);
//   }

//   private int coinChange(int[] coins, int rem, int[] count) {
//     if (rem < 0) return -1;
//     if (rem == 0) return 0;
//     if (count[rem - 1] != 0) return count[rem - 1];
//     int min = Integer.MAX_VALUE;
//     for (int coin : coins) {
//       int res = coinChange(coins, rem - coin, count);
//       if (res >= 0 && res < min)
//         min = 1 + res;
//     }
//     count[rem - 1] = (min == Integer.MAX_VALUE) ? -1 : min;
//     return count[rem - 1];
//   }
// }

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```