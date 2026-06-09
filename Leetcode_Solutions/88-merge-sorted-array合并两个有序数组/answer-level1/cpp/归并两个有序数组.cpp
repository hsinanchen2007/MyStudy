### 解题思路
三指针

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //初始化三个指针，分别指向nums1，nums2,和合并得最后位置
        int index1=m-1;
        int index2=n-1;
        int indexMerge=m+n-1;
        //当index<0表示对应数组遍历结束
        while(index1 >= 0 || index2 >= 0){
            //判断index1和index2是否小于0必须写在比较俩值大小前面，否则会导致最后一次数组溢出
            if(index1 < 0){//是否nums1遍历结束
                nums1[indexMerge--] = nums2[index2--];
            }else if(index2 < 0){
                nums1[indexMerge--] = nums1[index1--];
            }else if(nums1[index1] > nums2[index2]){
                nums1[indexMerge--] = nums1[index1--];//较大值放入后面
            }else if(nums1[index1] <= nums2[index2]){
                nums1[indexMerge--] = nums2[index2--];
            }
        }
    }
};
```