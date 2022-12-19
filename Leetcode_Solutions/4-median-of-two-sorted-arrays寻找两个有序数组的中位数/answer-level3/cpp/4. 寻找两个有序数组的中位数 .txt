### 解题思路
思路：
将nums1 和 nums2 拼接，然后排序。找出中间值。

### 代码

```cpp

#include <vector>

class Solution {
public:
    // 希尔排序
    void sort_vector(vector<int> &num)
    {
        int i=0,j=0,gap,num1;
        //分组
        for(gap = num.size()/2;gap>0;gap /=2)
        {
            //直接插入排序
            for(i=gap;i<num.size();i++)
            for(j = i-gap;j >= 0 && num[j] > num[j+gap]; j -= gap)
            {
                num1 = num[j];
                num[j] = num[j+gap];
                num[j+gap] = num1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len;
		double num = 0;
        if(nums1.size()<=0 && nums2.size()<=0)
        return 0;

        for(int i=0;i<nums2.size();i++)  // 拼接
        {
        	nums1.push_back(nums2[i]);
		}
        if(nums1.size()<=1)
        return nums1[0];
        sort_vector(nums1);     // 排序
        if(nums1.size()%2 == 0)    //  偶数个
        {
        	num = (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
            return num;
        }
        else 
        {
        	num = nums1[(nums1.size()-1)/2];
        	return num;
		}
        
    }
};
```