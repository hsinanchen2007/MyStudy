### 解题思路
此处撰写解题思路
现推了一番，主要是没记住。。
翻转就是对每一个区间的每一个元素进行翻转，即第一个与该区间最后一个元素交换，依次交换下去。


我当时忽略了k>len的情况，切记。
算法有待改进，大家一起学习！
### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if(k>len) k=k%len;
        reverse(nums,0,len-k);
        reverse(nums,len-k,len);
        reverse(nums,0,len);
    }
    void reverse(vector<int>& nums,int begin,int end){
        int i=begin,j=end,temp;
        while(j>i){
            temp=nums[j-1];
            nums[--j]=nums[i];
            nums[i++]=temp;
        }
    }
};
```