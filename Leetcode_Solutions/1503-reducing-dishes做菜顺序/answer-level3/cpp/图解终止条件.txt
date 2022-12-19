![image.png](https://pic.leetcode-cn.com/3d1e1879f530a2cc5ab592674a73c5a056f94abdc163d7bce6e7a2b7df8c8b0d-image.png)

这题先逆序之后，就比较清晰了，
1，每次增加的就是把所有选中的元素求和，然后添加到结果中(ans += tmpSum),
2，终止条件（黄色区域），就是这次所有元素和为负数时(tmpSum<0)，就返回。

参考了https://leetcode-cn.com/u/ikaruga/ 的分析。
```
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0;
        sort(satisfaction.begin(), satisfaction.end());
        reverse(satisfaction.begin(), satisfaction.end());
        int tmpSum = 0;
        for(int i =0; i<satisfaction.size(); i++) {
            tmpSum += satisfaction[i];
            if(tmpSum < 0) break;
            ans += tmpSum;
        }
        return ans;
    }
};
```
