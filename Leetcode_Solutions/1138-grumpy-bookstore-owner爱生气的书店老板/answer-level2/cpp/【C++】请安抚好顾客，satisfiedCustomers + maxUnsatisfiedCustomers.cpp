```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/19
 */
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
    {
        if (X <= 0) {
            return 0;
        }

        if (customers.empty()) {
            return 0;
        }
        if (customers.size() != grumpy.size()) {
            return 0;
        }

        int count = customers.size();
        int satisfiedCustomers = 0;
        vector<int> unsatisfiedCustomers(count + 1, 0);
        for (int i = 0; i < count; ++i) {
            satisfiedCustomers += (grumpy[i] == 1 ? 0 : customers[i]);
            unsatisfiedCustomers[i + 1] = (grumpy[i] == 0 ? 0 : customers[i]) + unsatisfiedCustomers[i];
        }

        int maxUnsatisfiedCustomers = 0;
        for (int i = X; i <= count; ++i) {
            int currentWindow = unsatisfiedCustomers[i] - unsatisfiedCustomers[i - X];
            maxUnsatisfiedCustomers = max(maxUnsatisfiedCustomers, currentWindow);
        }
        return satisfiedCustomers + maxUnsatisfiedCustomers;
    }
};
```
