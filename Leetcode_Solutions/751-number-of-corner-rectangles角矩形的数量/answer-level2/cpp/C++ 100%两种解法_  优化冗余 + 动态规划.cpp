## 一丶 数组map优化模型法
### 战绩
![image.png](https://pic.leetcode-cn.com/7039d6f0d09f9323cc0c107c7d8f2c64316d01bf5f44227a01162fb8d331ab8a-image.png)

### 解题思路
首先说明 思路不是我的原创 是我在别人基础上优化而来的 yeah~
1. **主题思想**: <两行>为一个大轮 然后记录下对应两行的"宽"(竖线)的个数 然后用组合数公式 $\color{red}{C^{2}_n\,=\,\frac{n\times(n-1)}{2}}$ 这样就能得到对应两行内所有可能的矩阵啦 翻译为人话就是: 在n个竖线中**无顺序**的选择两列即得到对应组成矩阵的个数 两列加上基准的两行构成了四边咯 而两行在确定后是只有1种情况 乘以1省去 
**扩展:** 
如果是全1的矩阵 根据排列组合知识算其中四角矩阵的个数为`(行数 * (行数 - 1) / 2) * (列数 * (列数 - 1) / 2)` 思想就是先确定两行再确定两列 而两行有`行数 * (行数 - 1) / 2`种可能 两列有`列数 * (列数 - 1) / 2` 根据组合数学的`乘法原理` 完成计算全1矩阵中角矩阵个数的任务有两步 第一是求得两行的个数 第二是求得两列的个数 再一乘就得到结果啦
2. **优化**: 重点 如果直接只按主题思想做 速度不够快 因为在确定两行 遍历两列是否同时为1时 会有大量不满足条件的情况 那么这些情况就叫"冗余" 如果能去掉这些冗余 那么速度就更快了 运用的办法的称之为`数组map模型`或`两数之和模型` 见[两数之和leetcode](https://leetcode-cn.com/problems/two-sum/) 就是准备一个数组待遍历和一个map精准"打击"这个数组中元素有没有 即数组中元素和map中"有"的元素存在某种`等价关系` **最后计算结果与常规法结果也一样** 所以你要准备一个所有行中元素为1的下标矩阵咯 对应为`idxv` 然后再要准备一个map结构 这样直接知道下一行的对应列中是否也为1 这个map就是下面的`map` 这样一轮提前工作 就去除了"冗余" 所以速度变快啦

### 代码




```cpp []
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& g) {
        vector<vector<int>> idxv(g.size(), vector<int>{});
        bool map[200][200]{};
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j]) {
                    idxv[i].push_back(j);
                    map[i][j] = true;
                }
            }
        }
        int n = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = i + 1; j < g.size(); j++) {
                int t = 0;
                for (int k = 0; k < idxv[i].size(); k++) {
                    if (map[j][idxv[i][k]]) t++;
                }
                n += t * (t - 1) >> 1;
            }
        }
        return n;
    }
};
```
```python []
class Solution:
    def countCornerRectangles(self, g: List[List[int]]) -> int:
        idxv = [[] for i in range(len(g))]
        map = [[0 for i in range(200)] for i in range(200)]
        
        for i in range(len(g)):
            for j in range(len(g[i])):
                if g[i][j]:
                    idxv[i].append(j)
                    map[i][j] = 1
        n = 0
        for i in range(len(g)):
            for j in range(i + 1, len(g)):
                t = 0
                for k in range(len(idxv[i])):
                    if map[j][idxv[i][k]]:
                        t += 1
                n += t * (t - 1) >> 1

        return n
```
python我是新手 这么写速度很慢 奇怪

**下面重头戏:**
不是我想出来的, 不过我领会了 (⊙o⊙)
## 二丶 动态规划
### 战绩
![image.png](https://pic.leetcode-cn.com/46348a0c58caf4f5afeb380f45c5b0caecd637443c0d864151c6e73ac70fdfb4-image.png)
会看到速度比上面还快 虽然可能不准确 但我感觉这个算法应该是更快些 代码也少得多
### 解题思路
我动态规划也才刚开始做题 所以可能有讲得不对地方
这个思想是首先确定`行` 然后确定`列` 第三确定`列+1`的项 而提速的关键不在于这个动态规划的解法核心部分 而在于`if(g[i][j])`这句话 即第三层循环开始只有在前置列元素为1时 才开始下面的列+1的循环 对比普通的两列扫描法(见[这位美女的](https://leetcode-cn.com/problems/number-of-corner-rectangles/solution/java-by-zxy0917-16/)) 核心代码都是差不多速度的 只是少了第三层循环开始前的前置判断 那么少的则是N方级的数量差 所以速度只有80ms 而上面提到的方法要250ms左右 所以速度快得多
动态规划怎么讲 是一种利用前面信息来做文章的技术 所有有递推公式 即需要找到当前轮与前面轮的关系 而这里的递推公式就是 $R_n\,-\,R_{n-1}\,=\,C^{2}_{n}\,-\,C^{2}_{n-1}\,=n\,-\,1$ 非常简单的计算就能得到 所以就是说 **在已知前面dp[j][k]中的数量后,下面再多加二点1增加的角矩阵数量只需要在原来dp中保存的数量加上当前次数** 这样说可能很抽象 关注点是在行确定后 列与列+1这些全1的两个点 然后行下移 再去关注列与列+1的全1的两个点 当然列和列+1的元素是会右移的 所以这个算法想出来很巧妙 很厉害
### 代码
```cpp []
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& g) {
        int dp[200][200]{}, n = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j]) {
                    for (int k = j + 1; k < g[i].size(); k++) {
                        if (g[i][k]) {
                            n += dp[j][k];
                            dp[j][k]++;
                        }
                    }
                }
            }
        }
        return n;
    }
};
```

```python []
class Solution:
    def countCornerRectangles(self, g: List[List[int]]) -> int:
        n, dp = 0, [[0 for i in range(200)] for i in range(200)]
        for i in range(len(g)):
            for j in range(len(g[i])):
                if g[i][j]:
                    for k in range(j + 1, len(g[i])):
                        if g[i][k]:
                            n += dp[j][k]
                            dp[j][k] += 1

        return n
```
弄懂在于**折腾** 希望大家有所收获.

类似 **动态规划题解:** [1277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/c-zi-chuang-shuang-zhong-gui-hua-shuang-zhong-ji-y/)