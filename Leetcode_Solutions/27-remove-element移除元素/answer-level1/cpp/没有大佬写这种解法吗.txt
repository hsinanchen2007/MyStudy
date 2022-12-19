### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,k=0;         //k用于记录nums中值为val的元素个数
        int len=nums.size();
        while(i<len){
            if(nums[i]==val) k++;   
            else nums[i-k]=nums[i]; //对于值非val的元素，将其前移k个位置，即用此元素覆盖在它
            i++;                    //之前值为val的元素
        }
        return len-k;
    }
};
```
其实是王道书上的一道算法题，还有另一种解法(用k记录值非val的元素个数),就不写出来了