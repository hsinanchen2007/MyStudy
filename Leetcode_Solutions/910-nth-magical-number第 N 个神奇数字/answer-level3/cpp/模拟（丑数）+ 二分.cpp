### 解题思路
模拟：O(N) 超时
二分：1e6

### 代码
#### 法1：模拟
```
const int MOD = 1e9 + 7;
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        // 倍数关系
        if (A > B) swap(A, B);
        if (B % A == 0) return (long) A * N % MOD;
        
        // 不互质的问题，约数可能多加一遍
        long head[] = {A, B};
        for (int i = 1; i <= N - 1; i ++) {
            if (head[0] <= head[1]) head[0] += A;
            else head[1] += B;
            if (head[0] == head[1]) head[0] += A; // 处理公倍数
        }
        return min(head[0], head[1]) % MOD;
    }
};
```
#### 法2：二分
```cpp
const int MOD = 1e9 + 7;
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        // 
        int d = gcd(A, B), s = A * B / d; // s最小公倍数
        
        long l = 0, r = 4e13 + 10;
        while (l < r) {
            long mid = l + r >> 1;
            if (mid / A + mid / B - mid / s >= N) r = mid;
            else l = mid + 1;
        }
        return l % MOD;
    }
    
    int gcd(int a, int b) {
        return !b ? a: gcd(b, a % b);
    }
};
```