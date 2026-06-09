```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/12/10
 */

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K)
    {
        vector<int> k;
        CalcArrayForm(K, k);

        vector<int> result;
        int aSize = A.size();
        int kSize = k.size();
        if (aSize > kSize) {
            AddArrayForm(result, A, k);
        } else {
            AddArrayForm(result, k, A);
        }
        return result;
    }

private:
    void AddArrayForm(vector<int> &result, vector<int> &big, vector<int> &small)
    {
        result = big;
        if (small.empty()) {
            return;
        }
        int lastBigIndex = big.size() - 1;
        int carry = 0;
        for (int i = small.size() - 1; i >= 0; --i, --lastBigIndex) {
            int data = small.at(i) + big.at(lastBigIndex) + carry;
            result[lastBigIndex] = data % 10;
            carry = data / 10;
        }
        if (carry > 0) {
            for (; lastBigIndex >= 0; --lastBigIndex) {
                int data = big.at(lastBigIndex) + carry;
                result[lastBigIndex] = data % 10;
                carry = data / 10;
            }
        }
        if (carry > 0) {
            result.insert(result.begin(), 1);
        }
    }

    void CalcArrayForm(int K, vector<int> &k)
    {
        stringstream ss;
        ss << K;

        string data = ss.str();
        for (int i = 0; i < data.size(); ++i) {
            k.push_back(data.at(i) - '0');
        }

        /*DumpArrayForm(k);*/
    }

    void DumpArrayForm(vector<int> &k)
    {
        for (int i = 0; i < k.size(); ++i) {
            cout << k.at(i) << endl;
        }
    }

};
```
