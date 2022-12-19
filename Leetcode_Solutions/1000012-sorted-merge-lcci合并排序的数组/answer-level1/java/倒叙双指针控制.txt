### 解题思路

因为两个数组是有序的，倒叙遍历两个数组，每次做出判断，大的插入到最后（两个数组长度之和）并且遍历长度减一，一次类推全部遍历完

### 注释


### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        //最大下标
        int max = m + n - 1;
        int j = n - 1, i = m - 1;
        //如果 n为空直接返回
        if (n > 0) {
            // 推出循环条件 是 AB都遍历完
            while (i >= 0 || j >= 0) {
                //B以及遍历完 剩下的全是A
                if (j < 0) {
                    while (i >= 0) {
                        A[max] = A[i];
                        i--;
                        max--;
                    }
                    break;
                }
                //A以及遍历完 剩下的全是B
                else if (i < 0) {
                    while (j >= 0) {
                        A[max] = B[j];
                        j--;
                        max--;
                    }
                    break;
                } 
                //对比大小 相应的值做计算
                else if (A[i] >= B[j]) {
                    A[max] = A[i];
                    i--;
                } else {
                    A[max] = B[j];
                    j--;
                }
                max--;
            }
        }
    }
}
```