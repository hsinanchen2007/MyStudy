### 解题思路

由于要对给出的数组arr进行从小到排序，而排序又不是这道题目的要点，
为了方便说明问题，在这里我不妨假设给的arr就是有序的（从小到大）

令n为数组arr的size;

当n=0或n=1时，显然要移动的次数为0；

当n=2时，要移动的次数为arr[1] - arr[0](也是显而易见的）

当n=3时，这种情况是要重点讨论的，
    为了使这三个数相等，我们分两步操作：
    Step1：先让前两个数相等，则需要移动的次数为arr[1] - arr[0]不妨记为count1;
            NOTE1：这里要注意，此时的第三个数字也已经受到影响，它增大了count1, 即 新arr[2] = 原arr[2] + count1（这一点很重要）
    Step2：此时前两个数已经相等了（这里所有相等的数字都可以当成一个数字），此时再上后两个数相等，即让arr[1] = 新arr[2],则需要移动
            新arr[2] - arr[1] = 原arr[2] + count1 - arr[1]不妨记为count2；
            最终经历count = count1 + count2 次移动达到了目的

当n>3时，等同n=3时的情况（数学归纳）

下面是实现代码，相信不难看懂

### 代码

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 对特列单独处理
        if(nums.empty() || nums.size() < 2){
            return 0;
        }

        // 对数组排序
        sort(nums.begin(), nums.end());

        // 累计移动次数
        int moves = 0;

        // 记录当前两个相临的数的差值
        int diff = 0;

        for(int i = 1; i < nums.size(); i++){
            // 更新相临两数的差值
            diff = nums[i] - nums[i - 1];

            // 累加移动次数
            moves += diff;

            // 这里是重点也是不好理解之处，这里的意义就是上述解题思路里的当n=3时的NOTE1
            if(i < nums.size() - 1){
                nums[i + 1] += moves;
            }            
        }
        return moves;
    }
};
```