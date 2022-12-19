```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/12/26
 */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        if (matrix.empty()) {
            return 0;
        }

        vector<int> data;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.at(i).size(); ++j) {
                data.push_back(matrix.at(i).at(j));
            }
        }

        sort(data.begin(), data.end());

        return data.at(k - 1);
    }
};
```
