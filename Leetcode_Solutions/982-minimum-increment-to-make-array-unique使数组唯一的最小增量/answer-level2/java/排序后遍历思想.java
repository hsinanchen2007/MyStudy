### 解题思路
此处撰写解题思路
先排序，然后遍历 速度中规中矩吧
### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A); //排序
        int move = 0;   //定义move（次数）
        for(int i=1;i<A.length;i++){//遍历数组
            if(A[i]<=A[i-1]){//因为经过排序 所以后面的数字必定需要大于前面的数字。因此MOVE的次数等于上一次move加上A[i]-x
                int x = A[i];
                A[i] = A[i-1] + 1;
                move = move + (A[i]-x);
            }
        }
        return move;
    }
}
```