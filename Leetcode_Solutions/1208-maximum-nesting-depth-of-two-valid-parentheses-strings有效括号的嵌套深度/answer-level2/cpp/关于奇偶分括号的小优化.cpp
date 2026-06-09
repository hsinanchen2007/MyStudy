今天这题目看了半天没看懂投降了，到评论区看了一下原来这么简单。看完评论区的题目解释，第一个也是想到两个括号组深度最接近，也就是左括号按奇偶分了。我画了一下真值表，发现最低位异或操作就是答案了。然后又因为 **“(”** 和 **“)”** 的ASCII码正好也是一奇一偶，那就直接拿ASCII码来运算了，这样就能消除if分支了，

```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        std::vector<int> res(seq.size());
        unsigned int index=0;
        for(auto&&e:seq)
        {
            res[index++]=(e^index)&1;
        }
        return res;
    }
};
```
