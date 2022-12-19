## 先把非零元素移到前面，再把后面元素置零
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int no = 0, len = nums.size();
        for(int i=0; i<len; i++){
            if(nums[i]!=0){
                nums[no++] = nums[i]; //把非零元素移到前面
            }
        }
        while(no<len) nums[no++] = 0; //把后面元素置零
    }
};
```