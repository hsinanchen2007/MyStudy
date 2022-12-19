> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/8deb79f22848c596564dea761d2c5773ab48cc7573f13e2ecd906caf3a87359a-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

## 题解
这题虽然难度定义成**困难**，但其实代码不长，思路也比较简单清晰。

首先明确一下题目中的两个条件，我们可以把所有人的分数在坐标轴中连起来，这样就形成了一个波形图（**图片来自官方题解**）：
![1.png](https://pic.leetcode-cn.com/a620cf04eeecc1afab32d9507dbe359a9ea7093588a2ed86b0cd2e80d09ed10e-1.png)

那么这就像一座一座山峰一样，在谷底（左右两边分数都大于等于它）糖果数一定是 $1$ 。从谷底往两侧扩展，糖果数逐渐加 $1$ 就行了。

要注意的一点是图中 pt.13 那个位置也是一个谷底，因为它右边的分数等于它。

那么问题的关键就是如何找到这些谷底了。

### 两次遍历
首先初始化所有人都分到 $1$ 个糖果。

然后从左向右遍历一次所有分数，如果发现分数小于等于前一个人分数，那暂时不用管，因为你从左向右是没法知道下坡的点距离谷底还有多远的。而如果发现分数大于前一个人分数，那么就在前一个人糖果数基础上，再多分一个给他，因为是上坡，所以谷底一定在左边已经遍历过了，是知道距离的。

接着就是遍历下坡了，也就是从右向左遍历所有分数，同理如果发现分数大于后一个人分数，那么就在后一个人糖果数基础上，再多分一个给他。

但是这里要处理一个冲突，那就是峰顶既是上坡，又是下坡，其实只要两次遍历完取上坡和下坡中糖果数较大的那个就行了。

总结一下就是**一次从左向右遍历所有上坡，一次从右向左遍历所有下坡，峰顶取两次较大值**。

时间复杂度 $O(n)$ ，空间复杂度 $O(n)$ 。

### 一次遍历
从上面方法中可以看出，本题求解的难点就在于从左向右遍历的时候，下坡到底有多长没法知道，必须全部遍历完了才能知道。还有就是山峰的值必须看左右两边的上坡下坡有多长。

为了解决这个问题，我们可以用变量 `up` 记录上坡的长度，`down` 记录下坡的长度。

当遇到谷底的时候，就表明一座山遍历结束了，那么我们只需要比较 `up` 和 `down` 的大小就知道峰顶取值了。

而如何判断一座山遍历结束呢？假设现在遍历到了第 $i$ 个学生，我们再用两个变量，`ns` 表示 $i-1$ 到 $i$ 的变化趋势（$1$：上升，$-1$：下降，$0$：不变），`os` 表示前一个时刻 $i-2$ 到 $i-1$ 的变化趋势。那么谷底只有下面三种情况：
* $os < 0$ 且 $ns > 0$ 。也就是前一个时刻在下降，当前时刻上升了，那显然第 $i-1$ 个学生是谷底。
* $os < 0$ 且 $ns = 0$ 。也就是前一个时刻在下降，当前时刻不变，这种情况下第 $i-1$ 个学生也是谷底，因为根据题意，他的糖果数没必要比第 $i$ 个学生多。
* $os > 0$ 且 $ns = 0$ 。也就是前一个时刻在上升，当前时刻不变。这种情况下，山峰只有上坡（到峰顶 $i-1$ 结束），没有下坡，所以这座山也遍历结束了，得计算糖果数了。

这座山峰的的糖果数可以表示为三部分之和：上坡、下坡和峰顶。上坡就是 $1+2+\ldots+up$，下坡就是 $1+2+\ldots+down$，峰顶就是 $\max{\{up, down\}}+1$ 。算完了之后，这座山峰就再也不用考虑了， `up` 和 `down` 都清零。

在具体实现的时候，这个方法细节有点多，一不小心就会错，直接看代码注释吧。

继续看下面这张图：
![1.png](https://pic.leetcode-cn.com/a620cf04eeecc1afab32d9507dbe359a9ea7093588a2ed86b0cd2e80d09ed10e-1.png)
贴一段官方的样例解释：
![2.jpg](https://pic.leetcode-cn.com/ab15b5881cb9f06103b8edf291fa63ac0f2babcf445686dca017bb1f69295813-2.jpg)


时间复杂度 $O(n)$ ，空间复杂度 $O(1)$ 。

### 单调栈
我们用一个单调栈来保存单调下降的得分，也就是下坡。

当遍历到第 $i$ 个学生时，如果栈顶元素 $j$ 的得分小于等于 $i$ 的得分，也就是遇到谷底了，那么就出栈，直到栈空。

最后用一个很大的数将栈里所有元素顶出来就行了。

时间复杂度 $O(n)$ ，空间复杂度 $O(n)$ 。

### 小结
第一种解法最容易理解和实现，也不用考虑什么特殊情况。但是后两种方法处理起来就稍稍有点麻烦了，需要结合样例和代码来理解。但是本质上都是一样的，都是从谷底（糖果数为 $1$）开始，向两周扩展。方法一是先从每个谷底向右边上坡扩展，再向左边下坡扩展。方法二是计算出相邻两个谷底之间的上坡下坡长度，然后直接计算。第三个方法是从每个谷底先向左边下坡扩展，再向右边上坡扩展。

## 代码
### 两次遍历（c++）
```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                res[i] = res[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                res[i] = max(res[i], res[i+1]+1);
            }
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};
```

### 一次遍历（c++）
```cpp
class Solution {
public:
    int count(int n) {
        return n*(n+1)/2;
    }

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 0;
        int up = 0, down = 0;
        int os = 0, ns = 0;
        for (int i = 1; i < n; ++i) {
            ns = ratings[i]>ratings[i-1] ? 1 : (ratings[i]<ratings[i-1] ? -1 : 0);
            // 这座山峰遍历结束，计算糖果数。
            if ((os < 0 && ns >= 0) || os > 0 && ns == 0) {
                // 这里看似好像峰顶没有加 1，其实是 count(down) 减去了 1。
                // 因为谷底是共享的，所以将谷底给了下一座山峰的上坡。
                sum += count(up) + count(down) + max(up, down);
                up = down = 0;
            }
            if (ns > 0) up++;
            else if (ns < 0) down++;
            // 如果是平原，说明谷底不会共享，之前少加的 1 再补上。
            else if (!ns) sum++;
            os = ns;
        }
        // 最后一座山峰循环里不会计算到，再加上。
        sum += count(up) + count(down) + max(up, down) + 1;
        return sum;
    }
};
```

### 单调栈（c++）
```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        ratings.push_back(INT_MAX);
        int n = ratings.size();
        vector<int> res(n, 1);
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (!st.empty() && ratings[i] >= ratings[st.top()]) {
                while (!st.empty()) {
                    int j = st.top();
                    st.pop();
                    if (j < n-1 && ratings[j] > ratings[j+1]) {
                        res[j] = max(res[j], res[j+1]+1);
                    }
                    if (j > 0 && ratings[j] > ratings[j-1]) {
                        res[j] = max(res[j], res[j-1]+1);
                    }
                    sum += res[j];
                }
            }
            st.push(i);
        }
        return sum;
    }
};
```