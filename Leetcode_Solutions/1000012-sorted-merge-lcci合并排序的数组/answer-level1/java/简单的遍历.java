### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] temp = new int[m + n];
        int index = 0;
        int left = 0, right = 0;
        while(left < m && right < n) {
            if(A[left] <= B[right]) {
                temp[index++] = A[left++];
            } else {
                temp[index++] = B[right++];
            }
        }
        
        while(left < m) {
            temp[index++] = A[left++];
        }
        
        while(right < n) {
            temp[index++] = B[right++];
        }
        
        for(int i = 0; i < m + n; i++) {
            A[i] = temp[i];
        }
    }
}
```