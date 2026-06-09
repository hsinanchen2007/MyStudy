### 解题思路
根据题目意思来就可以了，首先找到该行，该行所有元素加1，其次找到该列，该列所有元素加一，嵌套循环即可。
### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int[][] arr = new int[n][m];
        for(int i = 0;i<indices.length;i++) {
            for(int j = 0;j<n;j++) {
                arr[j][indices[i][1]]+=1;
            }
            for(int k = 0;k<m;k++) {
                arr[indices[i][0]][k]+=1;
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(arr[i][j]%2==1) count++;
            }
        }
        return count;
    }
}
```