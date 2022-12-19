### 解题思路
**详见代码注释**

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /**
            方法2:排序法————排好序，使用双指针比较是否相等，如相等且与数组最后值不重复，则压入数组
            时间复杂度:O(nlogn)
            空间复杂度:O(n)
        */
        
        vector<int> arr;

        // 排序
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int i =0,j=0;
        while(i<nums1.size() && j<nums2.size())//此处选择并，因为出现升序数组越界，之后的数都不会匹配
        {
            if(nums1[i] < nums2[j]) i++;//指针根据情况往后遍历，下同
            else if(nums1[i] > nums2[j]) j++;
            else 
            {
                //如果该数与数组最后一个数不重复，或者数组为空时，可压入
                if(arr.empty() || arr[arr.size()-1] != nums1[i]) arr.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return arr;
    }
};
```