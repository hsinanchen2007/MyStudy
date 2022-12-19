### 解题思路
双指针法：
       1 开始两指针都指向开头位置。
       2 移动指针，指针0找0，指针1找非0，找到后进行下一步,没找到直接break。
       3 判断两指针位置，如果指针0位置在指针1位置前面，交换两数，指针0移动，指针1移动；否则只有指针1移动。
       4一旦两指针其中一个移动到尾端，则结束循环。
        时间复杂度O(n),空间复杂度O(1).

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto ite0=nums.begin();
        auto ite1=nums.begin();
        for(;ite0!=nums.end()&&ite1!=nums.end();++ite1){
            while(ite1!=nums.end()&&*ite1==0)
                ++ite1;
            if(ite1==nums.end()) break;//必须加这行，不然报错？？？(因为循环结束会递增ite1,所以此处必须判断是否达到尾端。每次递增迭代器必须判断是否到达尾端！！！)
            while(ite0!=nums.end()&&*ite0!=0)
                ++ite0;
            if(ite0!=nums.end()&&ite1!=nums.end()&&ite0-ite1<0){
                swap(*ite0,*ite1);
                ++ite0;         } 
        }
    }
};
```
![erwerwewwwww.PNG](https://pic.leetcode-cn.com/8dc96421f4d1ce555c6c514ab0c35f97a51aa4fc4a3e6937819d5553e5c35f0d-erwerwewwwww.PNG)
