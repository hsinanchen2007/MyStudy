### 解题思路
自己尝试了40min发现超时，故看了标准答案，复刻出来
### 知识点
双指针
### 感悟
方法这种东西知易行难。
本以为自己已经掌握双指针这种方法，现实却给了自己一记响亮的耳光：标准答案那么简洁，易读，自己的“双指针”写的是个锤子。一种类型的题需要反复练习。
### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0; 
        for(int j=0;j<size(nums);j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
    return i;
    }
};
```