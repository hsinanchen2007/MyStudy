### 解题思路
1. 建立一个hash表
2. 遍历A，B数组A[i] == B[i] => hashTable[A[i]]++; A[i] != B[i] => hashTable[A[i]]++, hashTable[B[i]]++;
3. 观察hashTable里是否有记录等于A.size()
4. 最后在求最少要交换几次就ok了
5. 时间和内存消耗都比较高，仅供初学者借鉴
### 代码

```cpp
class Solution {
public:
    int toRes(vector<int>& arr, int target) {
        int len = arr.size();
        int res = len;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                res--;
            }
        }
        if (res > len / 2) {
            res = len - res;
        }
        return res;
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> okNum(7, 0);
        int len = A.size();
        int res = len;
        bool isExist = false;
        for (int i = 0; i < A.size(); i++) {
            okNum[A[i]]++;
            if (A[i] != B[i]) {
                okNum[B[i]]++;
            }
        }
        for (int i = 1; i < 7; i++) {
            if (okNum[i] == len) {
                isExist = true;
                res = min(toRes(A, i), toRes(B, i));
                break;
            }
        }
        if (!isExist) res = -1;
        return res;
    }
};
```