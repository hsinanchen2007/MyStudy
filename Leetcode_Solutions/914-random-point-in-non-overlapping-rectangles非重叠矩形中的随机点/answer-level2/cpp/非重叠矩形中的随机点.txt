#### 方法一：二分查找

我们用 `w[i]` 表示第 `i` 个矩形 `rect[i]` 中整数点的数目，那么我们的随机算法需要使得每个矩形被选到的概率与 `w[i]` 成正比（这样也就保证了空间中的每个整数点被选到的概率都是相等的）。具体地，`rect[i]` 被选到的概率应当为 `w[i] / sum(w[i])`，其中 `sum(w[i])` 表示空间中的整数点数目之和。

令 `tot = sum(w[i])`，我们可以在 `[0, tot)` 区间内生成随机整数。假设生成的数为 `x`，那么我们需要找到满足 `prefix(w[i - 1]) <= x < prefix(w[i])` 的 `i`，其中 `prefix(w[i])` 表示前 `i` 个矩形中整数点的数目之和，此时我们选中了第 `i` 个矩形。我们可以使用二分查找，找出对应的 `i`。

在选中了第 `i` 个矩形后，我们也可以在 `[0, w[i])` 中再次生成随机数，来在这个矩形中随机选择一个点。更好的做法是我们仍然使用之前生成的数 `x`，令 `y = x - prefix(w[i - 1])`，我们只需要选择第 `i` 个矩形中的第 `y` 个点即可，对应的坐标为：

```
x_coord = x_start + y % (x_end - x_start + 1)
y_coord = y_start + y / (x_end - x_start + 1)
```

这相当于把第 `i` 个矩形中的坐标按照 `y` 轴优先的顺序依次排列，每一个点都可以通过上述的方式恢复到矩形中的坐标。

![bla](https://pic.leetcode-cn.com/Figures/882/targToPoint.png){:width=260px}

```C++ [sol1]
class Solution {
public:

    vector<vector<int>> rects;
    vector<int> psum;
    int tot = 0;
    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

    Solution(vector<vector<int>> rects) {
        this->rects = rects;
        for (auto& x : rects) {
            tot += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
            psum.push_back(tot);
        }
        uni = uniform_int_distribution<int>{0, tot - 1};
    }

    vector<int> pick() {
        int targ = uni(rng);

        int lo = 0;
        int hi = rects.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum[mid]) lo = mid + 1;
            else hi = mid;
        }

        auto& x = rects[lo];
        int width = x[2] - x[0] + 1;
        int height = x[3] - x[1] + 1;
        int base = psum[lo] - width * height;
        return {x[0] + (targ - base) % width, x[1] + (targ - base) / width};
    }
};
```

```Java [sol1]
class Solution {

    int[][] rects;
    List<Integer> psum = new ArrayList<>();
    int tot = 0;
    Random rand = new Random();

    public Solution(int[][] rects) {
        this.rects = rects;
        for (int[] x : rects){
            tot += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
            psum.add(tot);
        }
    }

    public int[] pick() {
        int targ = rand.nextInt(tot);

        int lo = 0;
        int hi = rects.length - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum.get(mid)) lo = mid + 1;
            else hi = mid;
        }

        int[] x = rects[lo];
        int width = x[2] - x[0] + 1;
        int height = x[3] - x[1] + 1;
        int base = psum.get(lo) - width * height;
        return new int[]{x[0] + (targ - base) % width, x[1] + (targ - base) / width};
    }
}
```

**复杂度分析**

* 时间复杂度：预处理的时间复杂度为 $O(N)$，随机选取的单次时间复杂度为 $O(\log N)$。

* 空间复杂度：$O(N)$。