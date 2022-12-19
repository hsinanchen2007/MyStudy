用一个数组映射一下转换后的数字就好了
```
class Solution {
public:
    bool confusingNumber(int N) {
        vector<int> ro{0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int tmp, res = 0, n = N;
        while (N) {
            tmp = ro[N % 10];
            if (tmp == -1) return 0;
            res = res * 10 + tmp;
            N /= 10;
        }
        return res != n;
    }
};
```