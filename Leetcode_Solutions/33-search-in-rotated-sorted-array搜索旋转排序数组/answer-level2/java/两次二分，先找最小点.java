### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] A, int target) {
        if(A == null || A.length == 0) {
            return -1;
        }
        int min = getMin(A);

        if(target >= A[min] && target <= A[A.length - 1]) {
            return bsearch(A, min, A.length - 1, target);
        } else {
            return bsearch(A, 0, min - 1, target);
        }
    }

    private int bsearch(int[] A, int start, int end, int target) {
        if(start > end) {
            return -1;
        }
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(A[mid] < target) {
                start = mid;
            } else {
                end = mid;
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

    private int getMin(int[] A) {
        int n = A.length;
        int start = 0, end = n - 1;
        int target = A[n - 1];

        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(A[mid] > target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        return Math.min(A[start], A[end]) == A[start] ? start : end;
    }
}
```