设置两个指针，分别指向0和非0元素，交换，并移动指针。
程序如下：
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros=0;
        int number=0;
        while(number<nums.size()){
            if(nums[number]!=0){
                swap(nums[zeros],nums[number]);
                zeros++;
            }
            number++;
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/8dc7b56c7f6f18adbf016a9c43e1e964535458519d7a3f9f40934d717169341f-image.png)
