这道题题目有点复杂，但是其实很简单，意思就是嵌套深度尽可能小，那么把嵌套部分分别分给A和B就好了，当深度为奇数时分给B，为偶数时分给A，那么就可以使得A和B两者分别分到了嵌套深度的一半，这样就可以保证最小了。
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> nums(seq.size(), 0);
        int depth = 0;
        nums[0] = 0;
        for (int i = 1; i < seq.size(); i++) {
            if (seq[i] == '(') {
                depth++;
                if (depth % 2 == 0) nums[i] = 0;
                else nums[i] = 1;
            }
            else {
                if (depth % 2 == 0) nums[i] = 0;
                else nums[i] = 1;
                depth--;
            }
        }
        return nums;
    }
};
```
