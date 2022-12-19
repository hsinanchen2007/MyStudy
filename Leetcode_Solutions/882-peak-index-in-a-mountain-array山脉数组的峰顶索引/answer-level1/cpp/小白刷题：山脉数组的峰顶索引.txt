单向扫描，大小关系变化马上返回对应索引

代码：
```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        for (int i = 1; i < len; i++) {
            if (A[i] < A[i - 1])
                return i - 1;
        }
        return -1;
    }
};
```
