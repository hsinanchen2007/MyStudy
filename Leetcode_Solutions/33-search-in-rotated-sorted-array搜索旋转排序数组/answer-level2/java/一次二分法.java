### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] A, int target) {
        if(A == null || A.length == 0) {
            return -1;
        }

        int start = 0, end = A.length - 1;

        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(A[mid] <= A[end]) {
                if(target >= A[mid] && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else {
                if(target >= A[start] && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            }
        }

        if(A[start] == target) {
            return start;
        }
        
        if(A[end] == target) {
            return end;
        }

        return -1;
    }
}
```