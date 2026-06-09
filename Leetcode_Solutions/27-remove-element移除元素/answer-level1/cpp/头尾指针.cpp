### 解题思路
题目采用的是头尾指针
主要思路是头指针递增直到指向的元素等于val，然后尾指针递减直到指向的元素不等于val，然后进行元素的移除与替换

在别的题解中看到有用erase来删除元素，vector为顺序容器，是连续存储的，erase会将指定的元素移除，并该元素后面的元素前移，在使用erase时，可以实现移除后数组元素顺序不变（题目中并无要求），但是也会带来不必要的操作，尤其vector的size很大时，erase操作更加费时。

第一次写题解，欢迎指正！~~~（-_-）~~~

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=0;
        int pos=nums.size()-1;
        while(len<=pos){
            if(nums[len]!=val)
                len++;
            else{
                if(nums[pos]!=val)
                    nums[len]=nums[pos];
                pos--;
            }
        }
        return len;
    }
};
```