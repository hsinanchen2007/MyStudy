规定 两两牵手， 01配，23配，那么根据奇偶性质，直接分开处理，使用贪心去寻找即可。
一遍处理到头即完成次数最小。
PS：记得要剔除原本已经是配对的一对
```
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int count = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if (row[i]%2 == 0 && row[i+1] == row[i]+1) {
                continue;
            }
            if (row[i]%2 == 1 && row[i+1] == row[i]-1) {
                continue;
            }
            if (row[i]%2 == 0) {
                //偶数，查找奇数
                for (int j = i+1; j < row.size(); j++) {
                    if (row[i]+1 == row[j]) {
                        int tmp = row[i+1];
                        row[i+1] = row[j];
                        row[j] = tmp;
                        count++;
                        break;
                    }
                }
            } else {
                for (int j = i+1; j<row.size(); j++) {
                    if (row[i]-1 == row[j]) {
                        int tmp = row[i+1];
                        row[i+1] = row[j];
                        row[j] = tmp;
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};
```
