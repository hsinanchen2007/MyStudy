[Leetcode-Java(更多题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_287_findDuplicate.java)

![20160101111128525.png](https://pic.leetcode-cn.com/5be752c29a193e3c0cf030559612baad93865c03c53ab6f715707369a2759095-20160101111128525.png)

> 如上图所示：两个指针同时从直线起点开始（顺时针循环），假设在x处第一次汇合，xo之间距离为x，那么快指针走过的路程为a+c+x,慢指针走过的路程为a+x，所以a+c+x=2(a+x),所以c＝a＋x，也就是SO之间的距离等于xo，所以令快指针从起点开始一次一步，慢指针从x开始，同时前进，则必会在O处相遇！

```java
    /**
     * 题意解读：
     * 1、数组只读==>不能对数组进行重排序==>排序取连续两个相同的
     * 2、O(1)空间==>不能用哈希等进行遍历存储==>哈希取出现次数>1的
     * 3、O(n^2)的时间复杂度==>少于2次循环遍历，可以一次循环或者二分
     * 如果没有上述限制，上面的方法都可行
     * <p>
     * 解题思路：
     * 仔细看题目，发现数组大小n+1，数组数字1-n，一定会存在重复数字
     * 从0开始遍历，最开始一条直线，到后面会形成个环，可参考这张图 https://img-blog.csdn.net/20160101111128525
     * 从图中来看，环和直线相遇的点就是重复数
     * 1.用快慢指针，找到第一次相遇的点
     * 2.将一个指针移至起始点，再次相遇的一定是环和直线相遇的点，也就是重复数
     *
     * @param nums
     * @return
     */
    public int findDuplicate(int[] nums) {
        // 1.找到第一次相遇点
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // 2.找第二次相遇点
        int ptr1 = nums[0];
        int ptr2 = slow;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
```