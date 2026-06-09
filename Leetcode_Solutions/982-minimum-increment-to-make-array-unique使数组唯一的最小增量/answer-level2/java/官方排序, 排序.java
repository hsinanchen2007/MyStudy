### 解题思路
参考官方排序方法:
eg: [3,2,1,2,1,7]
排序后: 1,1,2,2,3,7
要求只统计次数 所以最后结果一定是: 1,2,3,4,5,7
不管多的1变成了5还是4 都不影响最后结果

所以 按照这个来说 只要按照从小到大的次序一个一个增加就好了
默认后面的一定比前面的大 这样不会影响最后的结果


### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if (A == null || A.length == 0 || A.length == 1) {
            return 0;
        }
        Arrays.sort(A);
        int res = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i] <= A[i-1]) { //默认后面的一定比前面的数大
                int t = A[i-1]+1;
                res+=(t-A[i]); 
                A[i] = t;
            }
        }
        return res;
    }
}
```