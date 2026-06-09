### 解题思路
排序之后,相同的数字就挨在一起了.然后两个一组,遍历,若前面的大于等于后面的,就意味着后面的需要"最少"加到该值+1的时候.
每次都记录差值,即相差1的数目即可.
需要注意的是,记录的是处理前的差值.

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int N = A.length;
        int res = 0;
        for(int i=0;i<N-1;i++){
            if(A[i] >= A[i+1]){
                int pre = A[i+1];
                A[i+1] = A[i] + 1;
                res += A[i] + 1 - pre;//注意这里
            }
        }
        return res;
    }
}
```