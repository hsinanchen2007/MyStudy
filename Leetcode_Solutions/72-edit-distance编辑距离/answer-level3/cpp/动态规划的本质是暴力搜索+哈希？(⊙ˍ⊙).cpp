让我们先用 **分治(divide and conquer)** 的思想来**分解**一下子问题。然后用**搜索**解决这些子问题。

设有两个字符串 A，B，长度分别为 La，Lb。我们的每次操作都让 A，B 的相同后缀**尽可能的长**。

举几个例子理解下相同后缀：
* "abc" 和 "uio" 的相同后缀为空串 ""。
* "hjk" 和 "hjk" 的相同后缀有 "hjk", "jk", "k", ""。

因为在A中**增/删**字符和在B中**删/增** 是等价的，同样，在A，B中替换字符也是等价的。所以我们只操作 A，这可以使问题变得容易思考。

### 数据预定义
设 suffix 为 A，B的相同后缀，对于任意的字符串，必有相同后缀 suffix = ""。
当 suffix == B 时，且 La == Lb 时， 必有 A == B。
所以我们的目标是，在经过若干次操作后，让 suffix == B，且 A 的长度变为 Lb。

初始时，设 suffix = ""， ls = suffix.size()，pa = La - ls, pb = Lb -ls;
pa 和 pb 代表字符串 A，B 拿掉 suffix 后的剩余长度，即**将要被处理的前缀部分**。

### 分解子问题
尝试将 B[pb] (假设下标从 1 开始) 归入到 suffix 中，那么面临**两种情况**：
* **B[pb] 和 A[pa] 相等**，此时无需操作，有 suffix = B[pb] + suffix。pa = pa-1, pb = pb-1。
* **B[pb] 和 A[pa] 不相等**，根据题意我们有三种操作方法：
    * **替换**：A[pa] = B[pb]，此时显然 A[pa] == B[pb]。
    所以有 suffix = B[pb] + suffix。pa = pa - 1, pb = pb - 1。
    * **插入**：在A[pa] 后插入字符 B[pb]，此时显然有 A[**pa+1**] == B[pb]。
    所以有 suffix = B[pb] + suffix。**pa = pa**, pb = pb - 1。
    * **删除**：删除A[pa]。此时**无法保证 A [pa-1] == B[pb]**。
    所以有 **suffix = suffix，pa = pa-1, pb = pb**。

**也就是说我们可以将问题分解为四个子问题。**
我们用 match(A, B, pa, pb) 代表**字符串 A，B 的剩余前缀长度为 pb, pb 时**，达到目标的最小操作次数。
那么 match(A,B,pa,pb) 的解根据上述讨论的两种情况，可以分解为：
* B[pb] == A[pa]，对应的子问题为 match(A,B,pa-1,pb-1);
* B[pb] != A[pa]，
    * 替换：对应子问题 match(A,B,pa-1,pb-1)
    * 插入：对应子问题 match(A,B,pa,pb-1)
    * 删除：对应子问题 match(A,B,pa-1,pb)

那么可以得到一个递归式子。为描述简单用 f(pa,pb) 代表 match(A,B,pa,pb)：
$$
f(pa,pb) = \left\{ \begin{array}{c}
f(pa-1,pb-1)&, A[pa] == B[pb] \\ 
min(f(pa-1,pb-1),f(pa,pb-1),f(pa-1,pb))+1&, A[pa] != B[pb] \\     
\end{array}\right. 
$$

特别的，当 pa == 0 或 pb == 0 时，最优解显而易见为 f(pa,pb) = max(pa,pb)。
所以完整的递推式子为：
$$
f(pa,pb) = \left\{ \begin{array}{c}
max(pa,pb)&, pa == 0 || pb == 0 \\
f(pa-1,pb-1)&, A[pa] == B[pb] \\ 
min(f(pa-1,pb-1),f(pa,pb-1),f(pa-1,pb))+1&, A[pa] != B[pb] \\     
\end{array}\right. 
$$

### 解决重复子问题的计算
当一个子问题可以由多个较大问题分解而来时，面临着重复计算的问题，此时的计算总次数可能会随着分解深度增加而指数级增长~

记忆化搜索是解决这个问题的一种方法，即对于每个已经求解的子问题，把答案保存下来！这里是不是就有点动态规划中**dp数组**的味道了？(:有内味了吗？

### 图示
**有图图片大小限制，只花了部分状态，供大家参考！**
![image.png](https://pic.leetcode-cn.com/092eb50c7cacba1613d1603e4076e9b05ef4cc8295ff0e19c079b56400d3bc84-image.png)


话不多说，上代码，具体细节可以参考注释。
```
class Solution {
public:
    struct HashPair {
        size_t operator() (const pair<int, int> &a) const {
            return a.first * 1000007 + a.second;
        }
    };
    
    unordered_map<pair<int, int>, int, HashPair> record;

    int match(const string &w1, const string &w2, int p1, int p2) {
        auto it = record.find(make_pair(p1, p2));
        if(it != record.end()) { //该问题已经被求解，直接返回答案！
            return it->second;
        }
        if(p1 == 0) {
            return p2; //搜索到了叶子结点！直接可以获得答案！
        }
        if(p2 == 0 ){
            return p1; //搜索到了叶子结点！直接可以获得答案！
        }
        if(w1[p1-1] == w2[p2-1]) { //A[pa] == B[pb]，无需操作，继续求解子问题！
            int ans = match(w1, w2, p1-1, p2-1);
            record.insert(make_pair(make_pair(p1, p2), ans)); //记录答案。
            return ans;
        }
        //替换策略
        int ans = match(w1, w2, p1-1, p2-1) + 1;
        //插入策略
        ans = min(match(w1, w2, p1, p2-1) + 1, ans);
        //删除策略
        ans = min(match(w1, w2, p1-1, p2) + 1, ans);

        record.insert(make_pair(make_pair(p1, p2), ans)); //记录答案。
        return ans;
    }

    int minDistance(string word1, string word2) {
        return match(word1, word2, word1.size(), word2.size()); //目标问题较大时，考虑分而治之！
    }
};
```

# 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
* **分享周赛题解**
* **分享计算机专业课知识**
* **分享C++相关岗位面试题**
* **分享专业书籍PDF**