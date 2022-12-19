### 解题思路
/*
* 1.将每个元素的最远到达位置算出;
* 2.遍历数组元素，将每个元素达到最远位置取最大值，不断更新；
* 3.当该位置是数组长度减1时，即已到达最后一个位置;
* 4.最后一个元素不遍历，能直接达到尾部即可；
* 5.在遍历过程中，如果能达到数组尾部，直接跳出循环，提高效率。
* 特殊情况：
* 1.当可移动的最远位置小于当前数组下标，则false;
* 2.数组开头为0，直接false;
* 3.数组只有一个元素.
*/


### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlen=0;
        int len=0;
        if(nums.size()==1)
        {
            return true;
        }
        for(int i=0; i<(nums.size()-1); i++)
        {
            if(maxlen < i)
            {
                return false;
            }
            len=i+nums[i];
            if(len>maxlen)
            {
                maxlen=len;
            }
            if(maxlen >= (nums.size()-1))
            {
                return true;
            }
        }
        return false;
    }
};


```