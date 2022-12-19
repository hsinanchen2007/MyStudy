先贴下时间：
56ms, 超过100%
![image.png](https://pic.leetcode-cn.com/2a6ca02cec9a7ae4df6c0b81796f8035dca94f8e3e1ad4bcc03ff36106faa48a-image.png)

解法：
在两个数组都未排序，并且不知道大小的情况下，可以遍历nums2，并在nums1中找是否存在，如果存在，则将元素加到结果中，并将nums1该位置的元素置为null.
代码如下：
```
var intersect = function(nums1, nums2) {
    const res = []
    nums2.forEach((item) => {
        const index = nums1.indexOf(item)
        if (index !== -1){
            res.push(item);
            nums1[index] = null;
        }
    })
    return res;
};
```
如果排了序的话（假设升序），可以利用双指针的方式，遍历两个数组，比如遍历nums2，那么nums1的指针只要每次都保证指向大于等于nums2当前元素的元素即可。
如果nums1比较短的话，可以直接遍历nums1, 因为用js内置的方法会比循环效率高；
如果nums2非常大，以至于不能一次性加载到内存的话，还是需要遍历nums2, 并且分块加载遍历；
上述三种情况的具体代码就不贴了，如有错误，还请指正，谢谢。