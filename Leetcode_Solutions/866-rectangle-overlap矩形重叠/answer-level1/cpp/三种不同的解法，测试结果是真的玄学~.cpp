1. 第一种方法使用了考虑不同的重合情况，写起来有点复杂，但是居然是最快的。。。。运行了两遍都是0ms，大佬们快告诉我为什么这么快？（菜鸡不懂看汇编）
我瞎猜的是因为条件判断的产生短路所以比较快？
```
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :9.2 MB, 在所有 C++ 提交中击败了7.14%的用
class Solution {
private:
    // rec1在左下，而rec2在右上，判断是否重叠
    // 满足: x22 > x11, x21 < x12, y12 > y21, y11 < y22
    bool _leftbottom_rightup(vector<int>& rec1, vector<int>& rec2) {
        return rec2[2] > rec1[0] && rec2[0] < rec1[2] && // x
            rec1[3] > rec2[1] && rec1[1] < rec2[3]; // y
    }

    // x21 < x12, x11 < x22, y11 < y21, y12 > y22
    bool _leftup_rightbottom(vector<int>& rec1, vector<int>& rec2) {
        return rec2[0] < rec1[1] && rec1[0] < rec2[2] && // x
            rec1[1] < rec2[1] && rec1[3] > rec2[3];
    }

public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return _leftbottom_rightup(rec1, rec2) || _leftbottom_rightup(rec2, rec1) || 
            _leftup_rightbottom(rec1, rec2) || _leftup_rightbottom(rec2, rec1);
    }
};
```

2. 方法1的反向思维，同时写起来也是最简单而且比较容易想到的。
```
//执行用时 :4 ms, 在所有 C++ 提交中击败了62.18% 的用户
//内存消耗 :10.2 MB, 在所有 C++ 提交中击败了7.14%的用户

class Solution {
public:
    // 对于不重合的情况取反，是个更简洁的做法
	// 但极为玄学的是，这个解法时间上居然慢得多。。。
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[3] <= rec2[1] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[0] >= rec2[2]);
    }
};
```

3. 学到了新招，看坐标轴是否重合，很牛皮。。
```
//执行用时 :4 ms, 在所有 C++ 提交中击败了62.18% 的用户
//内存消耗 :9.6 MB, 在所有 C++ 提交中击败了7.14%的用户

class Solution {
public:
    // 考虑是否有重叠矩形，即rec1和rec2是否有交集
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) &&
            max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};
```