![123.png](https://pic.leetcode-cn.com/b895847ec64350fb48607414cbbdd27c41c778587c1b4a160669eb0d4caaf2b2-123.png)

#### 方法一：非原地算法

##### 算法

最简单的想法就是另外开一个长度为`m+n`的数组`C`，按顺序将元素从`A`和`B`中取出放入`C`中。完成后`C`就是有序数组，再将`C`复制到数组`A`中。

```java []
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] t = new int[n+m];
        int cur = 0, cur_B = 0 ,cur_A = 0;
        while(cur_A < m && cur_B < n){
            if(A[cur_A] > B[cur_B]) 
                t[cur] = B[cur_B++];
            else 
                t[cur] = A[cur_A++];
            cur++;
        }

        while(cur_B < n) t[cur++] = B[cur_B++];
        while(cur_A < m) t[cur++] = A[cur_A++];

        for(int i=0;i < n+m;i++) A[i] = t[i];
    }
}
```

#### 方法二：原地算法

##### 算法

由于`A`数组有充足的空间储存所有元素，可以利用`A`数组后半部分的内容储存已排好序的内容。但是，如果仍然按正向（从小到大）的方式排序，完成合并后还需要对数组`A`反向。所以，可以直接通过倒排的方式合并连个数组。

```java []
class Solution {

    public void merge(int[] A, int m, int[] B, int n) {
        int cur = n + m - 1, cur_A = m - 1, cur_B = n - 1;

        while(cur_A >= 0 && cur_B >= 0) {
            if(A[cur_A] < B[cur_B]) 
                A[cur] = B[cur_B--];
            else 
                A[cur] = A[cur_A--];
            cur--;
        }

        while(cur_B >= 0) A[cur--] = B[cur_B--];
    }

}
```

##### 复杂度分析

+ 时间复杂度：$O(m+n)$ <br> 指针移动$m+n$次。

+ 空间复杂度：$O(1)$ <br> 借助了`A`数组未使用的空间，只有3个指针的额外空间开销。