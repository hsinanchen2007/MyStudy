方法一、根据官方方法
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id1=-1,id2;
        int submin;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                id1=i-1;
                id2=i;
                break;
            } 
        }
        if(id1==-1) sort(nums.begin(),nums.end());
        else{
            submin=nums[id1+1];
            for(int i=id1+1;i<nums.size();i++){
                if(nums[i]>nums[id1]&&nums[i]<submin) {
                    submin=nums[i];
                    id2=i;
                }
            }
            swap(nums[id1],nums[id2]);
            sort(nums.begin()+id1+1,nums.end());
        }
    }
};
```
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id1=-1,id2;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                id1=i-1;
                break;
            } 
        }
        if(id1==-1) sort(nums.begin(),nums.end());
        else{
            sort(nums.begin()+id1+1,nums.end());
            for(int i=id1+1;i<nums.size();i++){
                if(nums[i]>nums[id1]) {
                    id2=i;
                    break;
                }
            }
            swap(nums[id1],nums[id2]);
        }
    }
};
```
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id1=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                id1=i-1;
                break;
            } 
        }
        if(id1==-1) sort(nums.begin(),nums.end());
        else{
            sort(nums.begin()+id1+1,nums.end());
            auto it = upper_bound(nums.begin() + id1, nums.end(), nums[id1]);
            swap(nums[id1],*it);
        }
    }
};
```

方法二、来自[zeroAc](https://leetcode-cn.com/problems/next-permutation/solution/c-fu-li-stl-next_permutation-yi-xing-gao-ding-by-z/)

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end()); 
    }
};
```

