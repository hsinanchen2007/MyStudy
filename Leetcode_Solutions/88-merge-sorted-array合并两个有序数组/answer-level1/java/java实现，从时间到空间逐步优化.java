**思路一：暴力法** 没啥说的直接B合并到A后面的预留位置，然后直接API对A进行排序。

```java
public void merge(int[] A, int m, int[] B, int n) {
    for (int i = 0; i < n; i++) {
        A[m+i]=B[i];
    }
    Arrays.sort(A);
}
```

时间复杂度：O((m+n)*log(m+n))	排序的复杂度

**思路二：双指针法** 最直接想到的双指针法就是像合并两个有序链表一样双指针分别指向两个数组开头，从前向后遍历两个数组。

但是本题中A数组要作为最终的结果数组，所以需要将A中的m个元素保存到A2数组中，然后像上述方法一样双指针遍历A2和B数组，合并保存到A数组中。

```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
    //保存nums1的m个元素
    int[] A2=new int[m];
    for (int i = 0; i < m; i++) {
        A2[i]=nums1[i];
    }
    //双指针比较并合并保存到nums1中
    int i=0,j=0,index=0;
    while (i<A2.length&&j<nums2.length){
        nums1[index++]=(A2[i]<nums2[j]?A2[i++]:nums2[j++]);
    }
    //两个数组有剩余时保存到nums1后面
    while (j<nums2.length)nums1[index++]=nums2[j++];
    while (i<A2.length)nums1[index++]=A2[i++];
}
```

时间复杂度：O(m+n)

空间复杂度：O(m)	保存nums1的m个元素。

**思路三：逆序双指针法** 不使用额外的数组去保存nums1的m个元素，从而优化空间。

方法就是：逆序！其实就是将思路二都逆向进行。

双指针分别指向nums1和nums2的尾部，逆序遍历，比较大的元素优先合并入结果数组；从结果数组的尾部向前保存并入的元素。

```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
    //指针都指向尾部，比较大的元素优先合并至nums1尾部
    int i=m-1,j=n-1,index=nums1.length-1;
    while (i>=0&&j>=0){
        nums1[index--]=(nums1[i]>nums2[j]?nums1[i--]:nums2[j--]);
    }
    //检查是否有剩余
    while (i>=0)nums1[index--]=nums1[i--];
    while (j>=0)nums1[index--]=nums2[j--];
}
```

时间复杂度：O(m+n)

空间复杂度：O(1)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 