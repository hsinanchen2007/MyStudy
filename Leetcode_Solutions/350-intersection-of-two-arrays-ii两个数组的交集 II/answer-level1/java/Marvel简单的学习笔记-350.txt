### 解题思路
采用Two Pointers（双指针）的思想。首先对两个数组进行排序，再用两个int变量i、j分别指向两个数组的下标，从0开始同时进行扫描，直到任意一个数组完成扫描，退出循环。循环过程中，若i、j指向的两个数组元素相同，则将其添加进结果数组中；否则，将指向较小元素的变量加一，即指向所在数组的下一个元素继续进行比较，循环往复，最终得到结果数组。
时间复杂度：O(nlogn)。用于两个数组的排序。
空间复杂度：O(n)。需要一个辅助数组，初始化长度为两个数组中的较小的数组的长度。

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i=0,j=0;
        int len=nums1.length;
        if(nums2.length<nums1.length)
            len=nums2.length;
        int[] aux=new int[len];
        int idx=0;
        while(i<nums1.length && j<nums2.length)
        {
            if(nums1[i]==nums2[j])
            {
                aux[idx++]=nums1[i++];
                j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        int[] output=new int[idx];
        for(int k=0;k<idx;k++)
            output[k]=aux[k];
        return output;
    }
}
```