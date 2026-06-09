### 解题思路
此处撰写解题思路

### 代码

```cpp

// 暴力解法，对于重复出现的数字，暴力递增,TL。
int minIncrementForUnique(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        unordered_map<int,int> mymap;
        vector<int> repeatA;
        int res = 0;
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); i++) {
            if (mymap[A[i]] == 0) {
                mymap[A[i]] = 1;
            } else {
                repeatA.push_back(A[i]);
            }
        }

        for(int i = 0; i < repeatA.size(); i++) {
            int temp = repeatA[i];
            while(mymap[temp]) {
                temp++;
            }
            res += (temp - repeatA[i]);
            mymap[temp] = 1;
        }
        return res;
    }


class Solution {
    
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        int res = 0;
        sort(A.begin(), A.end());
        for(int i = 1; i < A.size(); i++) {
        // 遍历数组，若当前元素小于等于它的前一个元素，则将其变为前一个数+1
            if(A[i] <= A[i-1]) {
                int pre = A[i];
                A[i] = A[i-1]+1;
                res += A[i] - pre;
            }
        }
        return res;
    }
};
```