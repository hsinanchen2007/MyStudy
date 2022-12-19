试除法求一个数的所有约数的思路：
直接从1开始遍历，如果 i 是否能被 n 整除，能整除的话，i 就是 n 的约数，然后将 i 和 n / i 加入到数组中，注意如果 n 是 平方数的话，就不要重复添加。
```
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}
```

那么用这个思路来做这个题。

```
int sumFourDivisors(vector<int>& nums) 
    {
        int res = 0;
        for (int j=0;j<nums.size();j++)
        {
            int n = 0;
            int s = 0;
            for (int i=1;i<=nums[j]/i;i++)
            {
                if (nums[j]%i == 0)
                {
                    n++;
                    s += i;
                    
                    if (i != nums[j]/i)
                    {
                        n++;
                        s += nums[j]/i ;
                    }
                }
            }
            if (n==4)
                res += s;
        }
        return res;
    }
```



