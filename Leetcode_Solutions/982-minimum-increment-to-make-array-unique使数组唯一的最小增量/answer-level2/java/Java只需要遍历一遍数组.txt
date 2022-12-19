### 解题思路
- 由于move操作只能将数递增，那么有序数组当出现数字相同时，只需要考虑右侧数即可
- 比如[1,3,3]， 递增1是毫无意义的，只需要递增最后一位3即可

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A == null) return 0;
        //将数组排序，这样只需要从左向右遍历即可
        Arrays.sort(A);
        int count = 0;
        for(int i = 1; i < A.length; i++){
            /*
            diff记录当相邻右侧数小于等于左侧数（因为左侧数可能进行过move操作
            ，可能存在小于的情况）时，右侧数应该进行的move操作次数
            */
            if(A[i-1] - A[i] >= 0){
                int diff = A[i-1] - A[i] + 1;
                A[i] += diff;
                count += diff;
            }
        }
        return count;
    }
}
```