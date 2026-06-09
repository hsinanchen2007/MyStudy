### 解题思路

基本逻辑就是，fast往前走，如果遇到非0的，就和slow交换。然后把fast设置为0.

然后值得注意的是，如果fast的位置不为0，我们还需要检查slow和fast是不是同一个位置。如果是同一个位置，就不能把slow设置为fast。

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int slow = 0 ,  fast = 0;
        while (fast < nums.size()){
            if (nums[fast] != 0 ){
                if ( slow != fast){
                nums[slow] = nums[fast];
                nums[fast] = 0;
                }

                slow++; //如果两个位置相同
            }
            fast++;
        }
        return ;

    }
};


```