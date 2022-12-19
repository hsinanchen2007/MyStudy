### 解题思路
从0-n一个个查下去会导致超时

### 代码

```c
bool checkPerfectNumber(int num)
{
        if (num <= 0)
            return false;
        int sum = 0;
        for (int i = 1; i * i <= num; i++)
            if (num % i == 0)
            {
                sum += i;
                if (i * i != num)
                    sum += num / i;
            }
        return sum - num == num;
}
```