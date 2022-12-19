### 解题思路
在A数组的首尾两端添加0，用index数组存储A数组中0的索引值，index[0] = -1,index[index.size() - 1] = A.size();  
第(i + K)个零的索引值-第i个零的索引值-1，比较取最大值为结果。
### 代码

```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        vector<int> index;
        int lenA = A.size();
        index.push_back(-1);
        for (int i = 0; i < lenA; i++){
            if (A[i] == 0)
                index.push_back(i);
        }
        index.push_back(lenA);
        int maxLen = 0;
        int len = index.size();
        //for (int i = 0; i < lenA; i++)
        //    cout << A[i] << " ";
        //类似0,0,0,1 4的例子
        if (K + 2 > len)
            maxLen = lenA;
        for (int i = K + 1; i < len; i++){
            maxLen = max(maxLen, index[i] - index[i - K - 1] - 1);
        }
        return maxLen;
    }
};
```