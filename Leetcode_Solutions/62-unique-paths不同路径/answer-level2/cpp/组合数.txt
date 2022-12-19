我首先想到的是组合数
### 1.确定起点终点，如何组合。
对于m  n的格子，起点坐标为`(0, 0)`,那么终点即为`(m -1, n -1)`。一共走了`m - 1 + n -1`步，其中 `m - 1`个向下，`n-1`个向右，所以问题可以变成从`m + n - 2`步中确定 `m - 1`步或者`n-1`步，这两者是等价的。
### 2. 计算组合数。
组合数公试为 `C(m,n) = n! / (m! * (n-m)!) (n >= m)`如果直接计算阶乘会越界，所以需要同时进行进行，直接上代码！
```
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n){
            return C(n -1, m + n -2);
        }
        return C(m -1, m + n -2);
    }

    int C(int m, int n){
        long long  ans = 1;
        int index = n - m;
        for(int i = n; i >m; i--){
            ans *= i;
            while(ans % index == 0 && index >= 2){
                ans /= index;
                index --;
            }
        }
        return ans;
    }
};
```
