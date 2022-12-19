### 解题思路
思路：本题采用的是贪心算法。
具体贪法是：
1.首先把这包令牌值从小到大排序，也代表了对应的能量值；
2.令牌点数小的话，我们就利用能量来换取分数；令牌点数大的话，我们就利用分数来换取能量。
  A.如果我们能量一直足够的话，就一直用最小的能量换取分数。
  B.如果我们能量不够的话，就用1分换一次最大的能量，然后循环A。

### 代码

```java
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        // 将令牌的值从小到大排序
        Arrays.sort(tokens);
        // 头尾双指针
        int head = 0, tail = tokens.length - 1;
        // result记录最后结果，score记录每次操作的分数
        int result = 0, score = 0;
        // 可以换取分数的情况
        // 1.head <= tail 的意思是保证每个令牌只被放置1次
        // 2.P >= tokens[head] || score > 0 的意思是A.能量换分数或者B.分数换能量，这两个条件之间记录一次最大值
        while (head <= tail && (P >= tokens[head] || score > 0)) {
            // A.能量够的情况下，就一直用能量换取分数，令牌放置为正面，指针后移一位
            while (head <= tail && P >= tokens[head]) {
                P -= tokens[head++];
                score++;
            }

            // 能量不够了，跳出循环，算一下当前情况下的最大分数
            result = Math.max(result, score);
            // B.用分数换能量
            if (head <= tail && score > 0) {
                // 从最大的能量（尾指针指向的位置）开始换，令牌放置为反面，指针前移一位
                P += tokens[tail--];
                score--;
            }
        }

        return result;
    }
}
```

稍微简化一下，一个意思。

```java
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        // 将令牌的值从小到大排序
        Arrays.sort(tokens);
        // 头尾双指针,头指针用来记录能量换分数，尾指针记录分数换能量
        int head = 0, tail = tokens.length - 1;
        // result记录最后结果，score记录每次操作的分数
        int result = 0, score = 0;
        // 可以换取分数的情况
        // head <= tail 保证每个令牌只被放置一次，必须条件
        while (head <= tail) {
            // 1.能量换分数，指针后移一位代表此令牌已经置为正
            if (P >= tokens[head]) {
                P -= tokens[head++];
                score++;
                // 算一下当前情况下的最大分数（局部最优解）
                result = Math.max(result, score);
            } else if (score > 0) {
                // 2.分数换能量
                // 换一个最大的能量（尾指针指向的位置），指针前移一位代表此令牌已经置为反
                P += tokens[tail--];
                score--;
            } else {
                break;
            }
        }

        return result;
    }
}
```