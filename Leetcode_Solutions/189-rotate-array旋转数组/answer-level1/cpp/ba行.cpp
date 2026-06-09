### 解题思路
此处撰写解题思路：将后边的k个数字放到 t 中，然后再将 nums中k个数字前边的数字后移，然后再将t中的数放到nums中
![image.png](https://pic.leetcode-cn.com/427671be5bf39e64aa8abfdf5b097ed6821df1399b742d0f4155d74a46cc9ec6-image.png)


### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1) return ;
        vector<int> t;
        int len = nums.size();
        if(k>len){
            k%=len;
        }
        for(int i = len - k ;i < len ; i++ ){
            t.push_back(nums[i]);
        }
        for(int i = len -1- k,j = 0; i >= 0 ; i--,j++){
            nums[len - 1 - j] = nums[i];
        }
        for(int i = 0; i < k ; i++){
            nums[i] = t[i];
        }      
    }
};
```