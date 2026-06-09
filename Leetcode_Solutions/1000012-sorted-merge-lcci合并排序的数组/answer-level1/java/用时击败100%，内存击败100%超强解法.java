![Snipaste_2020-03-03_21-55-22.png](https://pic.leetcode-cn.com/09d6f73de8e3a85f77b2cf219cd5201587772cbc546d5be868207e851d19cc4f-Snipaste_2020-03-03_21-55-22.png)

### 解题思路
这道题，首先要想到的是对于A的多余空间应该充分利用起来，可以做一个暂存区。然后看题目要求，要求A最终有序。那么想到各种排序算法，然后很容易想到插入排序最适合这道题的情况。进一步想到可以先把A原有m个数据挪到A的最后面m个位置上，给前面留出了n个位置（处理极端情况），然后相当于两个数组交替进行插入即可。在插入过程中，目标数组的大小随着A数组上值的插入会慢慢变大。

简单来说就是：
1. 把A的m个元素全部挪到A的最后m个位置
2. A与B分别在A的前n个元素上循环进行插入排序，知道某个数组插入完成。
3. 每当A插入一个元素，相当于目标数组的size+1（因为A空出来了一个）
4. 最后检查没有插入完全的数组，剩余元素直接添加上去即可。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if (m == 0){
            if (n >= 0) System.arraycopy(B, 0, A, 0, n);
            return;
        }
        if (n == 0)
            return;
        int len = m+n;
        for (int i=1;i<=m;i++){
            A[len-i] = A[m-i];
        }
        int i = n;
        int j = 0;
        int cur = 0;
        while (i < len && j < n){
            if (A[i] <= B[j]){
                A[cur++] = A[i];
                i++;
            }else{
                A[cur++] = B[j];
                j++;
            }
        }
        while (i < len){
            A[cur++] = A[i++];
        }
        while (j < n){
            A[cur++] = B[j++];
        }
    }
}
```