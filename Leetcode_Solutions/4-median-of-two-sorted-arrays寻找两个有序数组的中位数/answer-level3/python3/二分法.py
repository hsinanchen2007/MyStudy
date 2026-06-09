思路讲解：
我们找中位数，可以把两个数组进行合并，左边一堆 右边一堆，如下图
![image.png](https://pic.leetcode-cn.com/d3d266d4c18fd71741b6aedc284914f5f7cca8309d8506c7fe3bc35536bb7538-image.png)

分割的要求为ai < ai+1,ai < bj+1, bj < bj+1, bj < ai+1 一共是这4个条件，前两个自然满足，因为是排序好的。其实要做的就是找nums1和nums2的分割点，只需要找到一个数组的分割点，就可以得到另一个数组的分割点，因为需要满足

C1+C2 = len(nums1)+len(nums2) // 2

C1代表第一个数组分割后左边有多少个元素
如果分好之后，则中位数很好求，可以用实例看一下，比较直观
![image.png](https://pic.leetcode-cn.com/0e549d32f3afd74c239d08731950a1ef78842be10caf4713d0c479eeb54fd7e8-image.png)

假如num1长度和nums2长度和加起来为奇数时，结果为min(r1,r2)
![image.png](https://pic.leetcode-cn.com/6277ea7960623a953046392d25f2347725f6e605e74e0f8ec55942cde7fde820-image.png)

假如num1长度和nums2长度和加起来为偶数时，两个数组合并后的 左边 出一个值，右边出一个值，两个数算平均数
![image.png](https://pic.leetcode-cn.com/dd8602970f6e19e96f59ed1bb7df10e6c4cf539c508d7dade0c35080df9f4e8b-image.png)


所以，就是要用2分法 找到1个数组的分割点即可，另一个分割点也就知道了，然后就可以算出中位数
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        len1 = len(nums1)
        len2 = len(nums2)
        if len1>len2:
            return self.findMedianSortedArrays(nums2, nums1)
        low, high, cut1, cut2 = 0, len1, 0, 0
        while low <= high:
            cut1 = (high-low) // 2 + low
            cut2 = (len1 + len2) // 2 - cut1
            l1 = float('-inf') if cut1 == 0 else nums1[cut1-1]
            l2 = float('-inf') if cut2 == 0 else nums2[cut2-1]
            r1 = float('inf') if cut1 == len1 else nums1[cut1]
            r2 = float('inf') if cut2 == len2 else nums2[cut2]
            if l2 > r1:
                low = cut1 + 1
            elif l1 > r2:
                high = cut1 -1
            else:
                if (len1+len2) % 2 == 0:
                    l1 = l1 if l1 > l2 else l2
                    r1 = r1 if r1 < r2 else r2
                    return (l1+r1) / 2
                else:
                    return float(min(r1,r2))
```
