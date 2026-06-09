### 解题思路
勉勉强强能看懂吧

### 代码

```java
class Solution {
    int check=Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);//排序不是主要问题，爱咋优化咋优化吧
        Greedy(coins,amount,coins.length-1,0);
        if(check==Integer.MAX_VALUE){
            return -1;
        }
        else{
            return check;
        }
    }
    
    public void Greedy(int[] coins,int amount,int value,int total){
        if(amount==0){
            check=Math.min(check,total);
            return;//不必继续找了，因为接下来大额硬币会更少，势必要增加小额硬币，肯定不会是最小值
        }

        if(value<0){
            return;
        }

        int num=amount/coins[value];//目前面额最多需要几张

        for(int j=num;j>=0&&total+j<check;j--){//对于每个面额，如果少n张行不行。 当前总数需要小于check中保存的那个最小值，不然会错失最小结果
            Greedy(coins,amount-j*coins[value],value-1,total+j);
            //amount减去换好的，面额向前移动，total加上现在换好的硬币数
            //total+j<check,因为这是amount不是0，如果大于等于check了，j继续--，大额硬币又需要很多小额硬币替代，肯定不是最小值
        }
    }
}
```