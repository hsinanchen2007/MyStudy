可以理解成每隔k个字符进行一次处理。

但是需要注意类型转换，int / int的结果还是int，如果不显式转换成double会导致错误的结果。

```c++
string reverseStr(string s, int k)
{
    int length = s.length();
    int times = ceil(static_cast<double>(length) / k);
    for (int i = 0; i < times; ++i)
    {
        // 前k个
        if (i % 2 == 0)
       {
            reverse(&s[i * k], &s[i == times - 1 ? length : (i + 1) * k]);
        }
    }
    return s;
}
```

