## 1、后序遍历直接修改nums1

题目可知，两个数组的总长度是m+n，而nums1只有前m个元素有值。转换或者前序遍历，都需要额外的空间开销，只有直接修改nums1是最优解。

total指针指向合并数组的最后一位，依次后序比较nums1和nums2的每个元素，递减地放入合并数组同时total指针递减。当nums2的全部元素合并到nums1，就完成了。

代码：

```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
    //　total point to the last element
    int total=m+n-1;
    m--;
    n--;
    // insert all ele of nums2 into nums1
    while (n>=0){
        // move ele of nums1 firstly
        if (m>=0 && nums1 [m]>=nums2 [n]){
            nums1 [total] = nums1 [m];
            m--;
        }else{
            // move ele of nums2
            nums1 [total] = nums2 [n];
            n--;
        }
        // move total pointer forward
        total--;
    }
}
```



## 2、优化后序遍历

```java
while (n>=0){
    // move ele of nums1 firstly
    if (m>=0 && nums1 [m]>=nums2 [n]){
        nums1 [total] = nums1 [m];
        m--;
    }else{
        // move ele of nums2
        nums1 [total] = nums2 [n];
        n--;
    }
```

上面的判断中，假设nums1中的全部元素都已经比较并后移，这时再去逐个插入nums2的元素是低效的。

这里可以使用System.arraycopy的方法将nums2剩余的元素全部复制到nums1中，减少解法1中的判断步骤。

优化后：

```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
    int total=m+n-1;
    m--;
    n--;
    while (n>=0 && m>=0){
        if (nums1 [m]>=nums2 [n]){
            nums1 [total] = nums1 [m];
            m--;
        }else{
            nums1 [total] = nums2 [n];
            n--;
        }
        total--;
    }
    System.arraycopy(nums2, 0, nums1, 0, n);
}
```

