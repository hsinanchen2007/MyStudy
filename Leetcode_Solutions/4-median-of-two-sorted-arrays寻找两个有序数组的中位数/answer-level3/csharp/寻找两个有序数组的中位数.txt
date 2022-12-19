### 思路1：根据两个数组直接生成一个新的有序数组，然后再取中位数（比较暴力的方法，但是这种方法可读性会好些）


### 代码

```csharp
public class Solution {
     public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int totalLength = nums1.Length + nums2.Length;
            int[] newArray = new int[nums1.Length + nums2.Length];
            int n1 = 0;
            int n2 = 0;
            for (int i = 0; i < newArray.Length; i++)
            {
                if (n1 == nums1.Length)
                {
                    newArray[i] = nums2[n2++];
                }
                else if (n2 == nums2.Length)
                {
                    newArray[i] = nums1[n1++];
                }
                else
                {
                    if (nums1[n1] < nums2[n2])
                    {
                        newArray[i] = nums1[n1++];
                    }
                    else
                    {
                        newArray[i] = nums2[n2++];
                    }
                }
            }

            if (totalLength % 2 != 0)
            {
                return newArray[totalLength / 2];
            }
            else
            {
                return (newArray[totalLength / 2] + newArray[totalLength / 2 - 1]) / 2.0;
            }
        }
}
```