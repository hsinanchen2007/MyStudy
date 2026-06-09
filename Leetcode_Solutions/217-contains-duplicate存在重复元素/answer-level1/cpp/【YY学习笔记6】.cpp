### 解题思路
先将数组排序，若有重复数值，其一定相邻
### 知识点
sort(数组的首地址，数组末尾地址+1)函数
### 感悟
**1.**  当使用我这种方法时，重点不在于题目本身，而是理解sort函数内部原理（目前我只了解了其中一部分：快速排序）
**2.**  在使用sort函数时，无法用sort(nums,nums+length)(原因和nums是容器有关，不过目前还没有深究)
### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       int length=size(nums);
       if(length==0)return false;
       sort(&nums[0],&nums[length]);
       for(int i=0;i<length-1;i++){
           if(nums[i]==nums[i+1])
                return true; 
       } 
        return false;
    }
};
```