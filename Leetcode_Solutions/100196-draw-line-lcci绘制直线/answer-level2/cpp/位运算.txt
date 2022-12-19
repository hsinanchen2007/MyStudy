见注释

```
class Solution {
   public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        if (x1 > x2) swap(x1, x2);

        int numPerLine = w / 32;         // 每行 int 的个数
        int rows = length / numPerLine;  // 总行数
        int beginNum = x1 / 32;
        int beginOffset = x1 % 32;
        int endNum = x2 / 32;
        int endOffset = x2 % 32;

        vector<int> res;

        // 插入前 y-1 行的 和 第 y 行第前 beginNum 个 0
        int pre = y * numPerLine + beginNum;
        for (int i = 0; i < pre; i++) res.push_back(0);

        if (beginNum == endNum) {
            unsigned int mark1 = ~(0xFFFFFFFF << (32 - beginOffset));
            unsigned int mark2 = (0xFFFFFFFF << (32 - endOffset - 1));
            res.push_back(mark1 & mark2);
        } else {
            // 插入开始的 数
            unsigned int mark = 0xFFFFFFFF >> beginOffset;
            res.push_back(mark);

            // 插入中间的 -1
            for (int i = beginNum + 1; i < endNum; i++) res.push_back(-1);

            // 插入结束的 数
            unsigned int mark2 = 0xFFFFFFFF << (32 - endOffset - 1);
            res.push_back(mark2);
        }

        // 插入第 y 行第后 numPerLine-endNum-1 个 0 和 后 rows-y-1 行的 0
        int post = numPerLine - endNum - 1 + (rows - y - 1) * numPerLine;
        for (int i = 0; i < post; i++) res.push_back(0);

        return res;
    }
};

```
