### 解题思路
基本思想来源于归并排序，这道题基本上是归并排序的其中一趟。首先创建一个大小为nums.size()+nums2.size()的数组temp，用来存储最终排序的数组。
之后进行排序，直到有一个数组的所有元素都排到temp数组里退出循环。然后对另一个未完成排序的数组继续排序，直到该数组所有元素全部排到temp结束。
我们还要分析数组长度的奇偶性：
    当数组长度为奇数时：
        中位数就是temp数组长度除2 向下取整
        temp[(length1+length2)/2]
    当数组长度为偶数时
        中位数就是（temp数组长度除2 向下取整）和（它前面的数）的平均数 //记得除以2.0
        (temp[(length1+length2)/2]+temp[(length1+length2)/2-1])/2.0
### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int i,j,k;
        vector<int> temp(length1+length2, 0);
        for(i=0,j=0,k=0;i<length1&&j<length2;k++)
        {
            if(nums1[i]<nums2[j])
            {
                temp[k] = nums1[i];
                i++;
            }
            else
            {
                temp[k] = nums2[j];
                j++;
            }
        }
        while(i<length1)        
            temp[k++]=nums1[i++];
        while(j<length2)
            temp[k++]=nums2[j++]; 
        if((length1+length2)%2 ==1)      
            return temp[(length1+length2)/2];    
        else
            return (temp[(length1+length2)/2]+temp[(length1+length2)/2-1])/2.0;
    }
};
```