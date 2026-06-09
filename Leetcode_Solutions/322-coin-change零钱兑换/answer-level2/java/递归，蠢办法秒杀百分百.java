提交结果：
执行用时 :3 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :34.4 MB, 在所有 Java 提交中击败了99.05%的用户

思路：（可能不是很正规）
要使用尽可能少的硬币兑换，肯定是尽可能使用大额的硬币，但是有个问题是大额的硬币可能找不开啊，举个简单的例子：现在有100,30,1共三种硬币，我要凑120，尽可能使用大额硬币的话方案应该是一个100加上二十个1，很明显不对，没有四个30使用硬币少。  所以直接找还是不行，还是得递归或者回溯，我用的是直接递归，递归的过程就在代码里面体现了就不说了 ，说一下可取的点，虽然尽可能使用大额的硬币不能直接得到答案，但是我们可以得到一点有用的东西，我使用100的硬币得到的答案虽然不是最小的，但是也算是比较小的了，在这里是21枚硬币，我们可以借助这个21排除一些方案，比如我全选1的硬币肯定不行，120/1==120远大于21 直接排除。

代码：
```
class Solution {
     int minCount=Integer.MAX_VALUE;
     public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        useNext(0,amount,coins,coins.length-1);//递归调用，从尾向首递归调用，尽量使用大额硬币
        if (minCount==Integer.MAX_VALUE)return -1;
        else return minCount;
    }
    //i是已经用了多少个硬币，amount是剩下金额，coins是硬币集合，n是第几种硬币
     private void useNext(int i, int amount, int[] coins, int n) {
        if (amount==0){ //找到一种组合
            if (i<minCount)minCount=i;
            return;//结束
        }
        if(n==-1||amount/coins[n]+i>=minCount)return;//尝试失败，压根就不用进行后面的循环
        for (int j = amount/coins[n]; j >=0 ; j--) {//尽可能多的使用大硬币，
            useNext(i+j,amount-coins[n]*j,coins,n-1);
        }
    }
}
```
