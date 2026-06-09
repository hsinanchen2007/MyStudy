```
public static void Merge(int[] nums1, int m, int[] nums2, int n)
        {
            for(int i = 0; i < nums2.Length; i++) {
                int j = m - 1 + i;
                for (; j >= 0; j--)
                {
                    if (nums1[j] > nums2[i])
                    {
                        nums1[j + 1] = nums1[j];
                    }else
                    {
                        nums1[j + 1] = nums1[j];
                        break;
                    }
                }

                nums1[j+1] = nums2[i];
            }
        }
```
