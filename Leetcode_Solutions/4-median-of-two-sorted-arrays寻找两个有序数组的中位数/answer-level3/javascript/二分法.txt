### 解题思路

参考了https://www.youtube.com/watch?v=do7ibYtv5nk，视频中的代码还是有点问题的，按照视频的思路用js写了一下，并且把视频中的一些没注意到的问题，和视频的代码的bug修复了，并按自己的理解记录了解题思路

- 中位数的概念，一个或者两个数把整一个数列分为比中位数大或者比中位数小两个部分，这**两个部分中元素个数是一样的**

- 分组
    + 正常思路是先整合排序，再找，那么复杂度是基于你排序的方式，很难符合题目的O(log(m+n))
    + 但是先排序后找的做法给了一点提示，那就是：如果是中位数，那么中位数的**左边的个数 == 右边的个数**
    + 因此我们只要找到一个分组的方式，让组里左边的元素必须小于右边的元素就好了
    + 这个分组明显只要对一个数组进行分组就行了，由于中位数左右个数一样，所以也就确定了另一个数组的分组

- 分组是否成功的条件
    + 对于分组是否成功的判断条件也很简单，也就是左边的数必须小于右边的数，也就是numsL < numsR
    + 又因为**数组都是排序好的**，所以只要比较两个分组分界线左右两边的数字大小就好了
    + 设nums1 分界线左边为L1 右边为R1, 同理L2 R2
    + 又因为已排序，所以同一个数组内L1 R1大小是一定确定的即L1<=R1
    + 所以只要判断L1<=R2就好了同理L2R1

- 调整分组
    + 我们假定nums1是较小的，我们只要处理小的那个数组就可以让复杂度再降低变成O(log min(m,n))
    + L1>R2 那么证明我们分组边界L1大了，应该往左移，反之，R1<L2，证明分组小了，改右移
    + 又因为事件复杂度是log函数，所以明显要用到二分法

### 代码

```javascript
var findMedianSortedArrays = function(nums1, nums2) {
    // 防止最小数组为空
    if (nums1.length == 0) {
        var middle = parseInt(nums2.length / 2)
        return nums2.length % 2 ? nums2[middle] : (nums2[middle] + nums2[middle - 1])/2
    }
    // 防止两个长度都为1的时候进bug
    if (nums2.length == 1 && nums1.length == 1) {
        return (nums2[0] + nums1[0]) / 2
    }
    // 确保nums1是小数组，继续优化时间复杂度，变为O(lb min(m,n))
    if (nums1.length > nums2.length) {
        return findMedianSortedArrays(nums2, nums1)
    }
    var len = nums2.length + nums1.length
    var cut1 = 0
    var cut2 = 0
    var cutL = 0
    var cutR = nums1.length
    while (cut1 <= nums1.length) {
        // 二分法，在视频中这里在加了 cutL是错误的二分
        cut1 = parseInt((cutL + cutR)/2)
        // 因为中位数左右两边相等，所以第二组的数量是这样的
        cut2 = parseInt(len/2) - cut1
        // 要考虑边界条件
        var L1 = (cut1 == 0) ? -Infinity : nums1[cut1 - 1]
        var L2 = (cut2 == 0) ? -Infinity : nums2[cut2 - 1]
        var R1 = (cut1 == nums1.length) ? Infinity : nums1[cut1]
        var R2 = (cut2 == nums2.length) ? Infinity : nums2[cut2]
        // console.log(R1,L1,R2,L2)
        // 判断分组条件是否正确，否，则继续二分
        if (L1 <= R2 && L2 <= R1) {
            return (len % 2) ? Math.min(R1,R2) : (Math.max(L1,L2)+Math.min(R1,R2))/2 
        } else if (L1 > R2) {
            cutR = cut1 - 1
        } else if (R1 < L2) {
            cutL = cut1 + 1
        }
    }
};

```