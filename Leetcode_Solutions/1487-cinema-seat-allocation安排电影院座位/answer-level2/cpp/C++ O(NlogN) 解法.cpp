![1386.png](https://pic.leetcode-cn.com/b599f140d22c41efe1f7e0f59ac43d691d13867a2657ae0e49bfcf01b9cb31f7-1386.png)

### 思路
对reservedSeats进行排序，然后分别讨论reservedSeats中出现的每一行占用情况，最终得解。
代码应该比较容易理解。

### 题解
```
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int count = 2 * n;  // 如果没有预约，总的安排数量

        sort(reservedSeats.begin(), reservedSeats.end()); // 进行排序
        for (int i = 0; i < reservedSeats.size();)
        {
            int row = reservedSeats[i][0];
            bool seats[11] = {false};
            
            // 初始化第row行的作为占用情况，记录在seats中
            int j = i;
            while (j < reservedSeats.size() && reservedSeats[j][0] == row)
            {
                int seatNo = reservedSeats[j][1];
                seats[seatNo] = true;
                j++;
            }
            count = count + numberOfChoice(seats) - 2; // 对row行进行处理
            i = j;
        }
        return count;
    }

    int numberOfChoice(bool seats[])
    {
        int count = 0, flag = 0;
        if (!seats[2] && !seats[3] && !seats[4] && !seats[5]) flag = 1, count++;
        if (!seats[6] && !seats[7] && !seats[8] && !seats[9]) flag = 1, count++;
        if (!seats[4] && !seats[5] && !seats[6] && !seats[7] && !flag)
            count++;
        return count;
    }
};
```
