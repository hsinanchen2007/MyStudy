### 解题思路
1. 从数组A的最后位开始比较，大的放后面
2. 如果B有剩下的则依次添加到A，还是视频表达更加形象（总感觉者题解只有自己能懂）

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if(n == 0) return;
        int i = m - 1, j = n - 1, index = m + n - 1;
        while(i >= 0 && j >= 0){
            A[index--] = A[i] >= B[j] ? A[i--] : B[j--];
        }
        for(int k = j; k >= 0; k--){
            A[k] = B[k];
        }
    }
}
```