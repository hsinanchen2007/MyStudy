### 解题思路
解法效率低了一点，但是思路很明确
1. 获取墙的宽度lineWidth
2. 遍历计算每一层墙缝的位置
3. 把所有缝的位置都存到map中，key=缝的位置，value等于缝出现的次数
4. 找出value最大值，用层数减掉缝出现最多的次数，就是穿过的转投个数

### 代码

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int linesNum = wall.size();
        vector<vector<int>> seams;
        map<int,int> seamsCount;
        int lineWidth = 0;
        for (auto brick : wall[0]) {
            lineWidth += brick;
        }
        for (auto line : wall) {
            vector<int> lineSeams;
            int seamPosition = 0;
            for (auto brick : line) {
                seamPosition += brick;
                if (seamPosition != lineWidth) {
                    lineSeams.push_back(seamPosition);
                }
            }
            seams.push_back(lineSeams);
        }
        for (auto line : seams) {
            for (auto seam : line) {
                seamsCount[seam]++;
            }
        }
        int maxNum = 0;
        for (auto &seam : seamsCount) {
            if (seam.second > maxNum) {
                maxNum = seam.second;
            }
        }
        return linesNum - maxNum;   
    }
};
```