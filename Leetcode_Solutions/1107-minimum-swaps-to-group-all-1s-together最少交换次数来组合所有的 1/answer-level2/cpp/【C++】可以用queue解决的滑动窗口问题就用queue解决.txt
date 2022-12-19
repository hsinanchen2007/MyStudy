1.计算sum
2.滑动窗口，流入流出一个元素，求和
3.求max
4.最大和和所有1的长度和的差值即为最小的交换次数
注：效率不高，刻意用下queue
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/09/23
*/

class Solution
{
public:
    int minSwaps(vector<int>& data)
    {
        if (data.empty()) {
            return 0;
        }
        vector<int> sums(data.size() + 1, 0);
        initSums(sums, data);

        int length = sums[data.size()];
        cout << length << endl;
        int maxCurrentSum = 0;
        maxCurrentSum = calcMaxCurrentSum(sums, length, data);
        return length - maxCurrentSum;
    }

    int calcMaxCurrentSum(vector<int> &sums,
                          int length,
                          vector<int> &data)
    {
        if (length <= 0) { // 如果窗长为0，不需要处理
            return 0;
        }

        int currentSum = sums[length];
        int maxCurrentSum = currentSum;// 第一次赋值
        queue<int> checkQueue;
        for (int i = 0; i < data.size(); ++i) {
            if (checkQueue.size() < length) {
                checkQueue.push(data.at(i));
            } else {
                int current = checkQueue.front();
                currentSum -= current;
                checkQueue.pop();
                currentSum += data.at(i);
                checkQueue.push(data.at(i));
                maxCurrentSum = max(maxCurrentSum, currentSum);
            }
        }
        return maxCurrentSum;
    }

    void initSums(vector<int> &sums, vector<int> &data)
    {
        sums[0] = 0;
        for (int i = 0; i < data.size(); ++i) {
            sums[i + 1] = sums[i] + data[i];
        }
    }

};
```
