### 解题思路
将数组排序后，开始遍历，如果A[i]>A[i-1] 说明没有重复的继续，
如果A[i]<A[i-1]，将A[i]=A[i-1]+1(这是避免重复且move代价最小的手段),并记录下move的代价

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int count = 0;
        int tmp;
        Arrays.sort(A);
        for (int i = 1; i < A.length; i++) {
            if (A[i] > A[i - 1]) continue;
            tmp = A[i];
            A[i] = A[i - 1] + 1;
            count = count + (A[i - 1] + 1 - tmp);
        }
        return count;
    }
}

```