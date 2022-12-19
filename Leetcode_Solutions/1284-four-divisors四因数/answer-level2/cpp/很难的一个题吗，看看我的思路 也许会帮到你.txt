- 定义一个方法，传入数组的每一个值。该方法的返回值是这样子的，如果这个值刚好四个因数，返回四个因数的和，否则返回0
- 方法内部层层筛选，具体代码里有解释
```
int getFourDivisors(int n)
{
    /* 3月23日 */
    int mid = int(sqrtf(n));
    if (mid * mid == n)
    {
        return 0;// 保证因数成对出现才会是4个 这种情况下总有一个会落单 直接返回0。
    }
    int index = 0; // index == 0 刚好一对因数  加上1和n 刚好四个 index == 1 两对 四个 index >= 1 因数个数大于4个 返回0
    int val = (1 + n);
    for (int i = 2; i <= mid; i++)
    {
        if (n % i == 0)
        {
            if (index == 1)
            {
                return 0;
            }
            val = val + (i + n / i);
            index++;
        }
    }
    if (index == 0)
    {
        return 0;
    }
    return val;
}
int sumFourDivisors(vector<int> &nums)
{
    int res = 0;
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        res += getFourDivisors(nums[i]);
    }
    return res;
}
```