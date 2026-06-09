**方法一：分治 + 四分查找**

题目中给出的 API `Sea.hasShips(topRight, bottomLeft)` 只能告诉我们某一个矩形区域中是否有船只，而我们的目标是得到船只的具体数目，因此我们必须通过 API 得到所有船只的位置，才能统计出船只的数目。

对于当前查找的矩形区域，如果 API 返回 `False` ，我们得到区域内没有船只，可以舍弃该区域。但如果 API 返回 `True`，我们得到区域内有船只，为了确定船只的位置，我们需要将区域划分成若干个互不相交的小区域，分别调用 API 继续进行查找。直到某一次查找的区域为一个点，即满足 `topRight == bottomLeft` 时，如果 API 返回 `True`，我们就确定了一艘船只的位置，可以将计数器增加 `1`。在查找完成后，计数器中的值即为船只的数目。

设当前查找的矩形区域右上角为 `(x1, y1)`，左下角为 `(x2, y2)`，一种常见的将其划分方法是取坐标的中点 `xm = (x1 + x2) / 2`，`ym = (y1 + y2) / 2`，将区域划分为四个小区域，它们为：

```
右上角小区域 (x1, y1) ~ (xm + 1, ym + 1)
右下角小区域 (x1, ym) ~ (xm + 1, y2)
左上角小区域 (xm, y1) ~ (x2, ym + 1)
左下角小区域 (xm, ym) ~ (x2, y2)
```

其中每个区域的第一个坐标为右上角坐标，第二个坐标为左下角坐标。这四个区域互不相交，且它们的并集为当前查找的区域。我们递归地对这四个区域进行查找，得到每个区域内船只的数目，累加后返回给上一层。注意这些小区域中可能由若干个区域并不是矩形，例如当 `(x1, y1) = (3, 6)`，`(x2, y2) = (3, 4)` 时，四个小区域分别为：

```
右上角小区域 (3, 6) ~ (4, 6)
右下角小区域 (3, 5) ~ (4, 4)
左上角小区域 (3, 6) ~ (3, 6)
左下角小区域 (3, 5) ~ (3, 4)
```

其中右上角和右下角的小区域并不是矩形。对于一个矩形区域，必须要满足 `x1 >= x2` 且 `y1 >= y2`。

综上所述，我们可以从最大的区域开始查找。如果当前查找的区域不是矩形或者 API 返回 `False`，我们返回 `0`，表示区域内没有船只。如果 API 返回 `True`，此时有两种情况：如果当前查找的区域为一个点，我们返回 `1`，表示找到了一艘船只；否则我们将该区域划分成四个小区域，递归地进行查找，返回的值为递归查找返回的值之和，即表示当前查找的区域内船只的数目。

```C++ [sol1]
class Solution {
public:
    int countShips(Sea& sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = topRight[0], y1 = topRight[1];
        int x2 = bottomLeft[0], y2 = bottomLeft[1];

        if (x1 < x2 || y1 < y2 || !sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }

        if (x1 == x2 && y1 == y2) {
            return 1;
        }

        int xmid = (x1 + x2) / 2;
        int ymid = (y1 + y2) / 2;
        return countShips(sea, {xmid, ymid}, {x2, y2}) + \
               countShips(sea, {xmid, y1}, {x2, ymid + 1}) + \
               countShips(sea, {x1, ymid}, {xmid + 1, y2}) + \
               countShips(sea, {x1, y1}, {xmid + 1, ymid + 1});
    }
};
```

```Python [sol1]
class Solution(object):
    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        x1, y1 = topRight.x, topRight.y
        x2, y2 = bottomLeft.x, bottomLeft.y

        if x1 < x2 or y1 < y2 or not sea.hasShips(topRight, bottomLeft):
            return 0

        if (x1, y1) == (x2, y2):
            return 1

        xmid = (x1 + x2) // 2
        ymid = (y1 + y2) // 2
        return self.countShips(sea, Point(xmid, ymid), Point(x2, y2)) + \
               self.countShips(sea, Point(xmid, y1), Point(x2, ymid + 1)) + \
               self.countShips(sea, Point(x1, ymid), Point(xmid + 1, y2)) + \
               self.countShips(sea, Point(x1, y1), Point(xmid + 1, ymid + 1))
```

**复杂度分析**

本题要求 API 的调用次数不能超过 `400` 次，因此我们用 API 被调用的平均次数来衡量时间复杂度。在右上角坐标为 `(1000, 1000)`，左下角坐标为 `(0, 0)`，船只数量为 `10` 且随机生成的情况下，API 平均调用的次数约为 `326`。

**方法二：分治 + 二分查找**

在方法一中，我们使用将一个区域分成四个小区域的方法，通过递归查找，得到船只的数目。由于题目中的船只数量最多为 `10`，它相对于最大的区域范围 `(1000, 1000) ~ (0, 0)` 而言是一个很小的数目，因此可以预见的是，我们会进行很多次失败（即 API 返回 `False`）的查找。例如当区域的大小为 `8 * 8` 但其中只有一艘船只时，我们会进行

```
1 次对 8 * 8 区域的查找，返回 True
4 次对 4 * 4 区域的查找，其中 1 次返回 True，3 次返回 False
4 次对 2 * 2 区域的查找，其中 1 次返回 True，3 次返回 False
4 次对 1 * 1 区域的查找，其中 1 次返回 True，3 次返回 False
```

总计 `13` 次 API 调用。

那么有什么办法可以减少失败的查找次数呢？设想一下，如果我们将区域仅划分为两个小区域 `A` 和 `B`，那么当对 `A` 区域调用 API 返回 `False` 时，我们可以直接断定，对 `B` 区域调用 API 一定会返回 `True`，这样就省去了一次 API 的调用。使用划分为两个而不是四个小区域的方法，我们会进行

```
1 次对 8 * 8 区域的查找，返回 True
1~2 次对 4 * 8 区域的查找，取决于第 1 个 4 * 8 区域是否返回 False
1~2 次对 2 * 8 区域的查找
1~2 次对 1 * 8 区域的查找
1~2 次对 1 * 4 区域的查找
1~2 次对 1 * 2 区域的查找
1~2 次对 1 * 1 区域的查找
```

总计 `7 ~ 13` 次，平均 `10` 次的 API 调用，优于方法一中的 `13` 次。

综上所述，我们得到了一种更优的方法：

- 我们从最大的区域开始查找；

- 对于当前的查找区域：

  - 如果它不是矩形，我们返回 `0`；

  - 如果它被断定为返回 `True`，我们可以不用调用 API，直接令 API 返回 `True`；如果它未被断定，则调用 API 并得到返回值；

  - 如果 API 返回 `False`，我们返回 `0`，表示区域内没有船只；

  - 如果 API 返回 `True`，此时有两种情况：如果当前查找的区域为一个点，我们返回 `1`，表示找到了一艘船只；否则我们将该区域划分成两个小区域 `A` 和 `B`，递归地进行查找。如果小区域 `A` 递归的结果为 `0`，那么我们断定对小区域 `B` 调用 API 一定会返回 `True`，省去一次 API 的调用；

  - 返回的值为对区域 `A` 和 `B` 递归查找的返回值之和，即表示当前查找的区域内船只的数目。

```C++ [sol2]
class Solution {
public:
    int countShips(Sea& sea, vector<int> topRight, vector<int> bottomLeft, bool claim = false) {
        int x1 = topRight[0], y1 = topRight[1];
        int x2 = bottomLeft[0], y2 = bottomLeft[1];

        if (x1 < x2 || y1 < y2) {
            return 0;
        }

        bool judge = (claim ? true : sea.hasShips(topRight, bottomLeft));
        if (!judge) {
            return 0;
        }
        if (x1 == x2 && y1 == y2) {
            return 1;
        }

        if (x1 == x2) {
            int ymid = (y1 + y2) / 2;
            int A = countShips(sea, {x1, ymid}, {x1, y2});
            return A + countShips(sea, {x1, y1}, {x1, ymid + 1}, A == 0);
        }
        else {
            int xmid = (x1 + x2) / 2;
            int A = countShips(sea, {xmid, y1}, {x2, y2});
            return A + countShips(sea, {x1, y1}, {xmid + 1, y2}, A == 0);
        }
    }
};
```

```Python [sol2]
class Solution(object):
    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point', claim: bool=False) -> int:
        x1, y1 = topRight.x, topRight.y
        x2, y2 = bottomLeft.x, bottomLeft.y

        if x1 < x2 or y1 < y2:
            return 0

        judge = True if claim else sea.hasShips(topRight, bottomLeft)
        if not judge:
            return 0
        if (x1, y1) == (x2, y2):
            return 1

        if x1 == x2:
            ymid = (y1 + y2) // 2
            A = self.countShips(sea, Point(x1, ymid), Point(x1, y2))
            return A + self.countShips(sea, Point(x1, y1), Point(x1, ymid + 1), A == 0)
        else:
            xmid = (x1 + x2) // 2
            A = self.countShips(sea, Point(xmid, y1), Point(x2, y2))
            return A + self.countShips(sea, Point(x1, y1), Point(xmid + 1, y2), A == 0)
```

**复杂度分析**

本题要求 API 的调用次数不能超过 `400` 次，因此我们用 API 被调用的平均次数来衡量时间复杂度。在右上角坐标为 `(1000, 1000)`，左下角坐标为 `(0, 0)`，船只数量为 `10` 且随机生成的情况下，API 平均调用的次数约为 `257`，优于方法一。在上面的 `8 * 8` 区域中仅有一艘船只的例子中，方法一平均调用 `13` 次 `API` 而方法二平均调用 `10` 次 `API`，根据方法一的总平均调用次数 `326`，我们计算出 `326 * (10/13) = 250.8` 与 `257` 十分接近。