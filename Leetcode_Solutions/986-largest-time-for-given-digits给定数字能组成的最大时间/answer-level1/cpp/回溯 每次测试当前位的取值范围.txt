### 解题思路
从最高位开始取值
第0位，其取值为0-2
第1位的取值与第0位取值相关，如果第0位为2，则第1位范围为0-3，否则为0-9
第2位为0-5
第3位为0-9
为加开匹配，对数组A排序，从A的最大值向最小值，找到第一个符合当前位的取值范围的最大值，
这里要注意，如果当前最大值的选取，导致后续无法获得结果，需要减小范围最大值，继续进行
特殊用例：A=[2,0,6,6]
### 代码

```cpp
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        if (A.empty()) {
            return "";
        }
        sort(A.begin(), A.end());
        if (A[0] > 2 || A[3] > 9 || A[0] < 0) {
            return "";
        }

        int arr[4] = {0};
        bool res = false;
        backtrace(A, arr, 0, res);
        if (res == false) {
            return "";
        }

        ostringstream oss;
        for (int i = 0; i < 4; ++i) {
            oss << arr[i];
            if (i == 1) {
                oss << ":";
            }
        }
        return oss.str();
    }
    void backtrace(vector<int>& A, int arr[], int cur, bool& res) {
        if (cur >= 4) {
            res = true;
            return;
        }

        int max = 0;
        switch (cur) {
        case 0:
            max = 2;
            break;
        case 1:
            max = (arr[0] == 2) ? 3 : 9;
            break;
        case 2:
            max = 5;
            break;
        default:
            max = 9;
        }

        for (int i = 3; i >= 0; --i) {
            if (max < 0) break;

            if (A[i] >= 0 && A[i] <= max) {
                arr[cur] = A[i];
                A[i] = -1; 
                backtrace(A, arr, cur + 1, res);
                A[i] = arr[cur];
                if (res == true) {
                    break;
                }
                --max;
            }
        }
    }
};
```