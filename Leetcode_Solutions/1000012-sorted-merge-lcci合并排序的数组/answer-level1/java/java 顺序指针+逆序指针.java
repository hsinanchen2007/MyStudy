### 解题思路

#### 顺序指针
最直接的思路就是，额外新建一个m+n长度的数组，指针分别从A数组B数组头部向后遍历，比较大小，并赋值给新建好的数组。


#### 逆序指针
根据题目，数组A尾部都会空出来0来放置排序的元素。
所以可以让指针分别总AB数组的m,n下标的位置向前遍历，比较大小，并从A数组尾部向前赋值。
这样就不用额外新建数组，可节省O(m+n)的空间复杂度。
但是感觉这样多少有些取巧了。



### 代码
#### 顺序指针
```java
 if (n <= 0) {
            return;
        }
        int a= 0;
        int b= 0;
        int r= 0;
        int[] res = new int[m + n];
        while (a< m && b< n) {
            if (A[a] < B[b]) {
                res[r++] = A[a++];
            } else {
                res[r++] = B[b++];
            }
        }
        while (a< m) {
            res[r++] = A[a++];
        }
        while (b< n) {
            res[r++] = B[b++];
        }
        System.arraycopy(res, 0, A, 0, m + n);
```


#### 逆序指针
```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
       if (n <= 0) {
            return;
        }
        int a = m - 1;
        int b = n - 1;
        int i = m + n - 1;
        while (a >= 0 && b >= 0) {
            if (A[a] > B[b]) {
                A[i--] = A[a--];
            } else {
                A[i--] = B[b--];
            }
        }
        while (b >= 0) {
            A[i--] = B[b--];
        }
    }
}
```