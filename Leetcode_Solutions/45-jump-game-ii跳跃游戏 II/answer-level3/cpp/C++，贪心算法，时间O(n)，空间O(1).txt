**思路：**
这道题目可以使用贪心算法来求解：从起始位置i开始，如果能够一步到达落点，则结束；
否则寻找下一个落点，选择的原则是，从下一个落点能够到达的位置最远。
也就是寻找i+1<=j<=i+nums[i]，使得j+nums[j]达到最大值。

**证明：**
反证法：
假设从起始位置，用贪心算法求出的下一个落点为i，而实际的最优解中下一个落点为j。
如果i能一步到达终点，那么按照贪心的定义，从j也能一步到终点；
如果从i不能一步到达终点，假设最优解中下一个落点为i'，那么按照贪心的定义，从j也能到达i'。
综上所述，完全可以将最优解中的第一个落点由j改为i，也就是最优解中第一个落点可以由贪心法求出。
求出第一个落点后，接下来要求解从i出发的子问题，可以按照同样的方法接着求出之后的每一个落点。

**优化：**
上面的方法时间复杂度为O(n^2)。实际上我们可以进一步优化，将时间复杂度降低到O(n)。
方法是：假设从i出发，下一个落点决定为i'，那么从i'出发寻找下一个落点时，不用从i'+1开始遍历，而直接从i+nums[i]+1遍历即可。
原因是，对任意j，i'<j<=i+nums[i]，从j出发能一步到达的最远位置，不会超过i'+nums[i']。
而从i'出发，如果下一个落点为i'+nums[i']，此时能一步到达的最远位置就已经超过了i'+nums[i']。
所以对于i'<j<=i+nums[i]，我们可以不用看，直接从i+nums[i]+1开始遍历。
这样在贪心过程中，需要维护一个变量start，每次从i跳到i'时，将其更新为i+nums[i]+1，下一次从i'跳时，从start开始遍历到i'+nums[i']。

**代码：**
```
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int i = 0, j, count = 0, start = 0;
        // 从位置i开始
        while(i < n-1){
            // 步数加1
            count ++;
            // 如果从i能一步到达终点，则结束
            if (i+nums[i] >= n-1)
                break;
            // 否则按贪心原则寻找下一个落点
            int max_distance = 0, next_jump = 0;
            for (int j=start; j<=i+nums[i]; j++){
                if (max_distance < j + nums[j]){
                    max_distance = max(max_distance, j + nums[j]);
                    next_jump = j;
                }
            }
            start = i+nums[i]+1;
            i = next_jump;
        }
        return count;
    }
};
```

