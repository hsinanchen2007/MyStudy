### 解题思路
先计算一共多少数字，偶数个数字还是奇数个数字
定位中位数在总体中的位置
想象有一个空白数组，然后我们比较nums1和2，每次选择其中较小的数字放入空白数组
直到放入数字的数量达到中位数的位置（即动态顺序并选择，不用全部排序）
当然不用空白数字记录数字，因为不是中位数的数字对我们的解题没有任何作用，所以不用存储他们
这样我们就需要两个指针去记录“虚拟”空白数组中的最后两个数
之所以用两个指针是为了适应偶数个数字中的中位数（中间两个数字平均数）

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //两个数组不会同时为空
        int * prePointer = nullptr;
        int * pointer = nullptr;
        int size = nums1.size() + nums2.size();
        if(size == 1){   //如果两个数组里面一共只有一个数
            if(nums1.size() == 0){
                return static_cast<double>(nums2[0]);
            }else{
                return static_cast<double>(nums1[0]);
            }
        }
        bool odd = false;
        int middle_index = 0;   //index 从1开始
        if(size % 2 != 0){
            odd = true;
        }
        if(odd == false){  //偶数
            middle_index = size / 2;
        }else{             //奇数
            middle_index = (size - 1) / 2;
        }
        //动态排序并找到中位数
        int nums1count = 0, nums2count = 0, count = 0;
        bool nums1end = false, nums2end = false;
        if(nums1.size() == 0 || nums2.size() == 0){
            if(nums1.size() == 0){
                nums1end = true;
            }
            if(nums2.size() == 0){
                nums2end = true;
            }
        }
        for(;count <= middle_index;){
            prePointer = pointer;
            if(nums1end){
                pointer = &nums2[nums2count];
                nums2count ++;
                count ++;
                continue;
            }
            if(nums2end){
                pointer = &nums1[nums1count];
                nums1count ++;
                count ++;
                continue;
            }
            if(nums1[nums1count] < nums2[nums2count]){
                pointer = &nums1[nums1count];
                nums1count ++;
                if(nums1count == nums1.size()){
                    nums1end = true;
                } 
            }else{
                pointer = &nums2[nums2count];
                nums2count ++;
                if(nums2count == nums2.size()){
                    nums2end = true;
                }
            }
            count ++;
        }
        if(odd){
            return static_cast<double>(*pointer);
        }else{
            return (static_cast<double>(*pointer) + static_cast<double>(*prePointer))/2;
        }
    }
};
```