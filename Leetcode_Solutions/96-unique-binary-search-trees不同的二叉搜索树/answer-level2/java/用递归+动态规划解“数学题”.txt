通过画图和数学知识推导出递推式:

f(n)=\sum_{i=0}^{n-1}f(n-i-1)*f(i)

我第一时间想到递归求解，本来以为会超时或者内存溢出，结果居然没有！！
```java
class Solution {
    public int numTrees(int n) {
        if(n==0 || n==1)
            return 1;
        int result = 0;
        for(int i = 0; i < n; i++){
            result += numTrees(n-i-1)*numTrees(i);
        }
        return result;
    }
}
```
耗时3s，打败5.01%，说实话能跑出来我已经很感谢了

当然为了优化，可以用动态规划中“自底向上的备忘录”来求解了，刚好我们也拥有动态规划所必需的递归式
```java
class Solution {
    public int numTrees(int n) {
        int[] result = new int[n+1];
        result[0] = 1;
        result[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j<i; j++){
                result[i] += result[i-j-1]*result[j];
            }
        }
        return result[n];
    }
}
```
显示用时0ms，打败100%，EXM？？