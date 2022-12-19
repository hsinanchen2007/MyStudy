以坐标距离为vector索引， 距离指定点可能是0, 1, 2, 3 ...

附代码：
class Solution {
public:
    struct pos {
        int r;
        int c;
    };

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int d;
        pos p; // 坐标
        int vLen = R + C - 1;
        vector<queue<pos>> res(vLen, queue<pos>()); // 同一个距离可能存在多个坐标点，依次加入队列
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                d = abs(r - r0) + abs(c - c0);
                p.r = r;
                p.c = c;
                res[d].push(p);
            }
        }
        vector<vector<int>> output;
        int size = res.size();
        for (int i = 0; i < size; i++) {
            while (!res[i].empty()) {
                p = res[i].front();
                res[i].pop();
                output.push_back({p.r, p.c});
            }
        }
        return output;
    }
};