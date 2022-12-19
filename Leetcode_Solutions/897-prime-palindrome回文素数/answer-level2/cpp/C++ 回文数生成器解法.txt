```
vector<int> digits(int n) {
    vector<int> nums;
    while (n > 0) {
        nums.push_back(n % 10);
        n /= 10;
    }
    reverse(nums.begin(), nums.end());
    return nums;;
}

bool isPrime(int n) {
    if (n < 2) return false;
    int t = sqrt(n);
    for (int i = 2; i <= t; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
// 回文数生成器
class PalindromeGenerator {
public:
    long start;
    long k;
    queue<long> nums;
    PalindromeGenerator(long s) : start(s) {
        vector<int> v = digits(start);
        k = v.size();
        long beg = 0;
        for (int i = 0; i <= (k - 1)/ 2; ++i) {
            beg *= 10;
            beg += v[i];
        }
        generateWithLenK(k, beg);
        ++k;
    };
    void generateWithLenK(long k, long beg = 0) {
        long m = (k - 1) / 2;
        beg = max(beg, (long)pow(10, m));
        long end = pow(10, m + 1);
        for (int i = beg; i < end; ++i) {
            long n = i;
            long t = i;
            if (k % 2 == 1) t /= 10;
            while (t > 0) {
                n *= 10;
                n += t % 10;
                t /= 10;
            }
            if (n >= start) {
                nums.push(n);
            }
        }
    }
    long next() {
        if (nums.empty()) generateWithLenK(k++);
        long res = nums.front();
        nums.pop();
        return res;
    }
};

class Solution {
public:
    int primePalindrome(int N) {
        auto pg = PalindromeGenerator(N);
        while (true) {
            int n = pg.next();
            if (isPrime(n)) return n;
        }
        return 0;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6fe5a1c5cb520c13f941a4c8e574a4c3d03181a5dfb36fd2fe65a73a321354bf-image.png)
