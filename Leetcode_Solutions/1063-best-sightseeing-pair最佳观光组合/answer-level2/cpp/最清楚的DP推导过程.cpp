一开始以为是单调栈，后来发现是DP。需要做两次子任务分解。具体可以看下图：
![WechatIMG23.jpeg](https://pic.leetcode-cn.com/d7765e3fbd33b6f854615a9155609d232cea3f6c9299fc625d79d5895b60bc89-WechatIMG23.jpeg)

有了上图，那么代码就很简单了！
```
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int fn = 0;            // f0
        int tn = A[0] + 0;     // t0
        
        for (int n = 1; n < A.size(); ++n){
            fn = max(fn, tn + A[n] - n);
            tn = max(tn, A[n] + n);
        }
        
        return fn;
    }
};
```
