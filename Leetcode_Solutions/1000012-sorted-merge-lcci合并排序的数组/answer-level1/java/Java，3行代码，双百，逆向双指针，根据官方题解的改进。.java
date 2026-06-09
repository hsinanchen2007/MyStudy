### 解题思路

思路跟官方解答一样，只不过做了一些小改动，使得代码看起来更“机智”（其实是可读性更差了）。
<br>
1. 改了while循环结构。
    现在while做将最大的元素置入A数组末尾，且只要pa/pb其中一个指针越界则跳出循环。
    如果pb指针越界了，说明B中所有数已经置入A中，而A本身就是有序的，所以不用再做任何操作了。
    如果pa指针越界了，说明A中剩下的位置需要用B中元素填充。
2. 取消了标志位tail，因为tail = pa + pb +1。（一个聊胜于无的修改）
    
     以上为个人见解，如有问题欢迎指出！共同学习！
        

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int pa = m - 1, pb = n - 1;
        while (pa > -1 && pb > -1) A[pa + pb + 1] = A[pa] > B[pb]? A[pa--] : B[pb--];
        if (pa == -1) while (pb > -1) A[pb] = B[pb--];
    }
}
```