这题直接将尾部元素插入到数组的头部这种做法会超时。这里通过反转数组来做

想象一下，这里有一串数组[1,2,3,4,5,6,7] ，k = 3  。首先反转整个数组[7,6,5,4,3,2,1] 然后反转目标子数组[5,6,7,4,3,2,1] 最后反转目标外子数组[5,6,7,1,2,3,4]符合题目要求。
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        if(k > l)
            k = k % l;
        for(int i = 0; i < l / 2; ++ i) //反转整串数组
            swap(nums[i],nums[l-1-i]);
        for(int j = 0; j < k / 2; ++ j) //反转目标子数组
            swap(nums[j],nums[k-1-j]);
        int flag = 0;
        for(int m = k; m < (l - k)/2 + k; ++ m) //反转目标外子数组
        {
            swap(nums[m],nums[l - 1 - flag]);
            ++ flag;
        }
    }
};
```
通过调用`reverse`函数来做能减少代码行数，思路同上
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()) k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
```