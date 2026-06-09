191题求汉明质量的解法都可以使用


```c++
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int n = x ^ y, count = 0;
        while (n)
        {
            ++count;
            n &= (n - 1);
        }
        return count;
    }
};
```
