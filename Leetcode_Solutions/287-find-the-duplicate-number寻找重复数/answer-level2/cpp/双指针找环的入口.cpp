### 解题思路
这道题目和环形链表一致，目的在于找寻环的入口。
我们首先看样例：
样例1：
nums  = [1,3,4,2,2];
index = [0,1,2,3,4];
所以，我们可以得到以下回环：
(nums[0] = 1) -> (nums[1] = 3) ->(nums[3] = 2) -> (nums[2] = 4) -> (nums[4] = 2);
所以，nums[2] -> nums[4] -> nums[2]就构成了一个闭环。环的入口处是2；

样例2：
nums  = [3,1,3,4,2];
index = [0,1,2,3,4];
同样可以得到回环：
(nums[0] = 3) -> (nums[3] = 4) -> (nums[4] = 2) -> (nums[2] = 3);
所以，nums[3] -> nums[4] -> nums[2] -> nums[3]就构成了一个闭环，入口处为3；

如果只进行回环的寻找的话，是可以找到处于同一环内的数据，但不一定就找到环口。

所以，根据之前的环形链表那一道题目的逻辑推导，我们可以知道，此时快指针从头走到和慢指针相遇，就可以找到链表的入口了。


### 代码

```cpp
class Solution {
public:
    //和循环链表类似，不过是下标的问题，根据下表来做事情
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            //进入循环链中
            if(slow == fast){
                fast = nums[0];
                //找循环链的入口
                while(fast != slow){
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return fast;
            }
        }
        return fast;
    }
};
```