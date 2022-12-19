### 解题思路
出现log的时间复杂度，一般都是二分查找法。看了下官方的解法和力友的解法，感觉还是力友的解法更好理解。

### 代码

```csharp
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.Length;
        int n = nums2.Length;
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }

    
    //i: nums1的起始位置 j: nums2的起始位置
    public int findKth(int[] nums1, int i, int[] nums2, int j, int k){
        if( i >= nums1.Length) return nums2[j + k - 1];//nums1为空数组
        if( j >= nums2.Length) return nums1[i + k - 1];//nums2为空数组
        if(k == 1){
            return Math.Min(nums1[i], nums2[j]);
        }
        int midVal1 = (i + k / 2 - 1 < nums1.Length) ? nums1[i + k / 2 - 1] : int.MaxValue;
        int midVal2 = (j + k / 2 - 1 < nums2.Length) ? nums2[j + k / 2 - 1] : int.MaxValue;
        if(midVal1 < midVal2){
            return findKth(nums1, i + k / 2, nums2, j , k - k / 2);
        }else{
            return findKth(nums1, i, nums2, j + k / 2 , k - k / 2);
        } 
    }
}
```