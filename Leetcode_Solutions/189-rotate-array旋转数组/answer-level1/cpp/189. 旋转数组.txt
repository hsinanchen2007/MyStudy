## 408真题の原地循环右移
**利用三次逆置，实现循环左移的操作**
```cpp
class Solution {
public:
    //逆置[left, right]
    void myReverse(vector<int>& nums, int left, int right){
        int temp;
        for(int i=left, j=right; i<j; i++, j--){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        myReverse(nums, 0, len-1);
        myReverse(nums, 0, k-1);
        myReverse(nums, k, len-1);
    }
};
```
## 右移k位相当于左移len-k位
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if(len==0) return;
        k %= len;
        for(int i=0; i<len-k; i++){
            nums.push_back(nums[i]);
        }
        for(int i=len-k; i<len+len-k; i++){
            nums[i-len+k] = nums[i];
        }
        nums.resize(len);
    }
};
```
## 暴力法
*略*