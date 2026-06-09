## 问题描述
给定一个正整数数组 nums。

找出该数组内乘积小于 k 的连续的子数组的个数。

![](https://pic.leetcode-cn.com/24f7ef5dcc687b53c94f84077065b8a745de07fbf51e1ac8bcb94c3522d73585.png)

[乘积小于k的子数组](https://leetcode-cn.com/problems/subarray-product-less-than-k/ "乘积小于k的子数组")

## 解决方法
### 双指针

- `temp`用来记录乘积

- `left`向右移动，`temp/=nums[left]`，直到`temp`小于`k`

- 结果加上本轮子数组下`nums[left:right]`符合条件的情况。（ps：值得深刻揣摩这句话）


```cpp
//暴力搜索
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int left=0,right=left,size=nums.size();
//         int temp=1,res=0;
//         for(int i=0;i<size;i++){
//             for(int j=i;j<size;j++){
//                 temp*=nums[j];
//                 if(temp<k)res++;
//                 else break;
//             }
//             temp=1;
//         }
//         return res;
//     }
// };
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,right=left,size=nums.size();
        int temp=1,res=0;
        while(right<size){
            temp*=nums[right];
            while(temp>=k && left<=right)temp/=nums[left++];
            //假如[10,2,6,5]，1000符合要求，那么总数就是10
            res=res+right-left+1;
            right++;
        }
        return res;
    }
};
```

个人网站：[liyiping](https://liyiping.cn)