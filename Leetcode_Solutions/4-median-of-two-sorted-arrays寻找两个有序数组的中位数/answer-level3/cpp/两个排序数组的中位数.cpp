不愧是困难题，还想着画画图可以想出来一点。然而……
看了答案，感觉主要是两种解法：
1. 将求中位数转化为求第k小的数。这种情况，对于`m+n`为奇数，就很容易理解。比如为7时，那么第4小的数就是中位数了。
但是，在`m+n`是偶数时，就需要处理一下。求得应该是`(m+n)/2`和`(n+m)/2+1`的平均值。该解法很巧妙，而且容易理解一些。
具体代码可见[此页面](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/)。
以下为此种方法的C++代码：
```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int med1, med2;
        //处理奇数和偶数的不同情况。如果是奇数那么会求2个相同的值。
        med1 = findKthNum(nums1, 0, l1-1, nums2, 0, l2-1, (l1+l2+1)/2); //+1是因为k表示第k小，从1开始。而不是从0开始。
        med2 = findKthNum(nums1, 0, l1-1, nums2, 0, l2-1, (l1+l2+2)/2); 
        return (med1+med2)*0.5;
    }

    double findKthNum(vector<int>& nums1, int s1, int e1, 
        vector<int>& nums2, int s2, int e2, int k) {
            int l1=e1-s1+1, l2=e2-s2+1;

            if(l1 > l2) //确保nums1一直是比较短的数组
                return findKthNum(nums2, s2, e2, nums1, s1, e1, k);

            if(l1 == 0) //比较短的数组已经全部被跳过
                return nums2[s2+k-1];

            if(k == 1) //求两个数组中，最小的数
                return min(nums1[s1], nums2[s2]);

            //找到分别需要比较的数的位置
            int idx1 = s1+min(l1, k/2) - 1;
            int idx2 = s2+min(l2, k/2) - 1;
            if(nums1[idx1] < nums2[idx2]) {
                return findKthNum(nums1, idx1+1, e1, nums2, s2, e2, k-(idx1 - s1 +1));
            }else
                return findKthNum(nums1, s1, e1, nums2, idx2+1, e2, k-(idx2 - s2 + 1));
    }
};
```

2. 第二种方法，就比较难理解。从中位数的定义开始推导，将求中位数转化为找到一个`i`，使得其满足一定的条件。之后，在处理各种边界情况。具体的推导过程，太长了，官方题解可以看到。