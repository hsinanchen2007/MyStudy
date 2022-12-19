思路：此题最重要是理解题意，而此题的题意是找出特殊数组（满足图示关系的数组）中的最大值所在的索引，于是可用多种方法解决。本文主要介绍三种解法，打桩法、双指针法、二分查找法。
下图为图示：

![image.png](https://pic.leetcode-cn.com/6268a3d16f99996ec3b9f7482f6c92b79a542ae6d1dddcb11fef358f8ef8d485-image.png)
<br/>
<br/>
解法一 ：打桩法，也叫单向扫描，代码如下：时间复杂度为O(n)，效率略低，但是此方法具有普适性，也就是说这个方法可适用于在一般数组中找最大值。
```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        if (A == null || A.length < 3)  {
            return 0;
        }
        
        int max = Integer.MIN_VALUE;
        int ans = 0;
        
        for (int i = 0;i < A.length;i++) {
            if (A[i] > max) {
                max = A[i];
                ans = i;
            }
        }
        
        return ans;
    }
}
```
<br/>
<br/>
解法二：双指针，也叫双向扫描，左右两边同时向中间扫描，以找出最大值，这个算法其实是在打桩法之上的一个效率优化，时间复杂度为O(n/2)--->O(n)，效率较低，但比打桩法效率高，同时也具有普适性。
```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        if (A == null || A.length < 3)  {
            return 0;
        }
        
        int max = Integer.MIN_VALUE;
        int ans = 0;
        
        int left = 0;
        int right = A.length - 1;
        
        while (left <= right) {
            if (left <= right && A[left] > max) {
                max = A[left];
                ans = left;
            }
            
            if (left <= right && A[right] > max) {
                max = A[right];
                ans = right;
            }
            
            left++;
            right--;
        }
        
        return ans;
    }
}
```
<br/>
<br/>
解法三：分治法，二分查找，是适用于此题的最佳解法，时间复杂度为O(logn)，优点是效率高，缺点是不具有普适性。因为此题数组特殊，所以可用这种方法提高查找效率。
```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        if (A == null || A.length < 3)  {
            return 0;
        }
        
        int ans = 0;
        
        int left = 0;
        int right = A.length;
        
        while (left < right) {
            int center = (left + right) / 2;
            if (A[center] > A[center - 1] && A[center] > A[center + 1]) {
                ans = center;
                break;
            } else if (A[center] < A[center - 1]) {
                right = center;
            } else {
                left = center;
            }
        }
        return ans;
    }
}
```