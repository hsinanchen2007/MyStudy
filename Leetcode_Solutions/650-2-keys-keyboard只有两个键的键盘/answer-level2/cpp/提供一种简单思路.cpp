想要操作次数最少，就要保证每次粘贴的字符尽可能多。
那么我们只需要找到n的最小因数i，这时的粘贴次数minStemps(n / i) + (1 + (i - 1))就是最少的。 其中1是copy次数，i - 1是paste次数。
如果n不能分解，则最少次数是1 + (n - 1)，即复制1次，粘贴n - 1次。
注意：因为起始条件下已经有一个字符，所以n == 1时，不需要进行任何操作，返回0。
c++超过100%。

class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        
        for (int i = 2; i <= n / 2; ++i)
        {
            if (n % i == 0)
                return minSteps(n / i) + i;
        }
        
        return n; // 1 + (n - 1)
    }
};