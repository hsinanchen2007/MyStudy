### 解题思路

括号匹配的问题初学C++的时候就有做过，用栈可以很方便的匹配两两配对的括号，用数组模拟栈也很容易。

不过这个题并不是让自己配对括号，题目已经说明传入的参数字符串 `seq` 已经是**有效括号字符串**，所以不用担心括号不配对或者存在其它字符的问题，字符串要么为空，要么就是已配对的并且只存在左右括号的字符串。

不管怎么分为两个字符串，它们各自的深度加起来一定是等于原字符串 `seq` 的深度的，同时最终的结果要取 `max(depth(A), depth(B))` 的最小可能取值，显然需要将 `depth(A)` ， `depth(B)` 应该均匀的分配。也就说如果原字符串的深度为 4，那么应该满足 `depth(A) = depth(B) = 2` ，如果原字符串的深度为 5，那么要么 `depth(A) = 3` ， `depth(B) = 2` ，要么 `depth(A) = 2` ， `depth(B) = 3` 。只要搞懂了这一点就很容易了。

根据题目要求返回的是一个和 `seq` 长度相等的 `vector<int>` 数组，所以可以直接定义这样一个数组并将其长度初始化为 `seq.size()` 。 `seq` 可能为空，为空可直接返回空数组。

分别定义 `maxDepth` 记录原字符串 `seq` 的最大深度，`depth` 记录 `seq` 中每一个括号的深度，遍历字符串 `seq` 对应记录每一个括号的深度到数组 `ans` 中。

虽然分组的方法不止一个，但是显然可以把内层的括号分为一组，外层的括号分为一组，这样就可以很容易得到两个深度相等或者深度相差1的有效括号字符串。只需要遍历上述记录了每一个括号深度的数组 `ans` ，将深度小于等于 `(maxDepth + 1) / 2` 的置为 `0` （或者 `1`），其余的置为 `1` （或者 `0`）即可。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        if (seq.empty())
            return ans;
        int maxDepth = 0;//最大深度
        int depth = 0;//用于记录每一个括号的深度
        //记录每一个括号的深度
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                depth++;
                maxDepth = maxDepth > depth ? maxDepth : depth;
                ans[i] = depth;
            }
            if (seq[i] == ')') {
                ans[i] = depth;
                depth--;
            }
        }
        //max(depth(A), depth(B))一定是maxDepth的一半取上整
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = ans[i] <= (maxDepth + 1) / 2 ? 0 : 1;
        }
        return ans;
    }
};
```