这个题解的加速关键是利用条件
* 1 <= dominoes[i][j] <= 9

有了这条限制，可以得到[i, j] 组合最多能够产生`(9*(9+1))/2=45`种多米诺可能，其中包括9种`[i,i]`的组合，以及36种`[i,j] && [j, i]`的组合。令i<j，则我们对这45种可能做i增序而后j增序的排列，即为{[1,1], [1,2],..., [1,9], [2,2], [2,3],..., [8,9], [9,9]}。

很容易想到用一个长度为45的整型数组来存储出现的次数。接下来的关键就是如何将这45种多米诺可能精准映射到一个长度为45的数组中去。
我们假设i<j （这个很容易做到），则在以i为开头的组合中，其第一个位置下标为9+8+...+(i+1)，j表示是以i开头的组合中的第j-i个数。
我们用一个长度为9的数组begin表示以i为开头的组合的起点：
```java
int[] begin = new int[] {0, 9, 17, 24, 30, 35, 39, 42, 44};
```
则[i, j]可以映射到的下标为：begin[i-1]+j-i
因此有如下代码：
```java
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int len = dominoes.length;
        if (len<=1)
            return 0;
        int[] begin = new int[] {0, 9, 17, 24, 30, 35, 39, 42, 44};
        int[] times = new int[45];
        int tmp=0;
        for (int i=0; i<len; i++) {
            if (dominoes[i][0] > dominoes[i][1]) {
                tmp = dominoes[i][0];
                dominoes[i][0] = dominoes[i][1];
                dominoes[i][1] = tmp;
            }
            times[begin[dominoes[i][0]-1]+dominoes[i][1]-dominoes[i][0]]++;
        }
        tmp=0;
        for (int i : times) {
            if (i>1)
                tmp += (i*(i-1))>>1;
        }
        return tmp;
    }
}
```