### 解题思路
将两数组合并为一个有序数组，然后找出中位数。

### 代码

```csharp
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        int[] nums3 = new int[len1 + len2];
        int j = 0, k = 0, i = 0;
        while(i < (len1 + len2) / 2 + 1)
        {
            if (j == len1 || k == len2)
            {
                if (j == len1 && k == len2)
                    break;
                if (j == len1)
                {
                    nums3[i] = nums2[k];
                    k++;
                    i++;
                    continue;
                }
                if (k == len2)
                {
                    nums3[i] = nums1[j];
                    j++;
                    i++;
                    continue;
                }
            }
            if (nums1[j] <= nums2[k])
            {
                nums3[i] = nums1[j];
                j++;
            }
            else
            {
                nums3[i] = nums2[k];
                k++;
            }
            i++;
        }
        if((len1 + len2) % 2 == 1)
            return nums3[(len1 + len2) / 2];
        else
            return (nums3[(len1 + len2) / 2] + nums3[(len1 + len2) / 2 - 1]) / 2.0;
    }
}
```