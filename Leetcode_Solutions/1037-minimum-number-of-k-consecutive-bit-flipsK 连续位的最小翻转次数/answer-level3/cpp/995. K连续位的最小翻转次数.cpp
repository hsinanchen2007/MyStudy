### 解题思路
本文参考了[Sh.TY](https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/solution/guan-fang-da-an-tai-nan-dong-la-hua-dong-chuang-ko/)的工作。

看到这道题时我是没有任何思路的，哪怕穷举法我也没想出来。等会做的时候，就又觉得一切思路都顺理成章。我觉得有些精妙的算法（只是一部分哈）是由暴力搜索发展而来的，那么我们就先从暴力搜索开始说起。

如何暴力搜索？机器能做的就是从头开始检索到最后，它是没有思路的。那么我们就想，从头开始检索，只要发现0，就一定要从那个元素开始翻转K位。为什么一定要从发现的0开始反转K位，而不翻转0前面的元素？因为0前面的元素都是1啊，你翻转了它反而坏事了！由此，暴力搜索就呼之而出了。

由于每次翻转都要更新一下数组，就很麻烦，现在我们考虑如何加快这个算法。简化的方法就是，**你明明想做翻转这件事，可是其实并没有真正做这件事，这样就加快的算法的速度**。怎么说呢？假设现在检索到了i元素，那么它是否需要翻转，取决于
1. 它原来的状态
2. 在它前面的k-1位元素总共翻转了几次（记为f）

如果i原来是1且f为奇数，或者i原来是0且f为偶数，那么i就一定要翻转。
由此，我们不用真正翻转，而是只记录以前的翻转状态就足够了。
如果检索到size-k位时仍需翻转，此时剩余位数不够k了，说明无法翻转，返回-1。

总结一下，这道题是从暴力搜索开始的，然后逐渐优化。

### 代码

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int *reverse = new int[A.size()]();
        int revNum = 0;
        int ans(0);
        for(int i=0;i<A.size();i++){
            if(A[i] == revNum%2){
                if(i+K > A.size())
                    return -1;
                reverse[i] = 1;
                ans++;
                revNum++;
            }
            if(i+1-K>=0 && reverse[i+1-K]==1)
                revNum--;
        }
        delete[] reverse;
        return ans;
    }
};
```