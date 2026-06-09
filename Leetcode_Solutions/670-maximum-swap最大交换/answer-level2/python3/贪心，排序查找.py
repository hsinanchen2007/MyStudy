
-   首先将所有字符进行逆序排序，然后从前面向后找，找到当前字符与逆序不同的数字，表示后面肯定有比当前数字大的
-   然后在后面找出最大的，并且位置最靠后的数字即可

```
例如：
299
逆序排序为：
992
第一个数字就不相同，因此，需要交换的就是这个位置
然后找到第2个9，交换，得到992
```



```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = list(str(num))
        sorted_num = list(sorted(num_str, reverse=True))
        length = len(num_str)
        pos = length
        for index, (n1, n2) in enumerate(zip(num_str, sorted_num)):
            if n1 != n2:
                pos = index
                break

        next_pos = pos + 1

        if pos < length:
            for i in range(next_pos + 1, length):
                if num_str[i] >= num_str[next_pos]:
                    next_pos = i
            num_str[pos], num_str[next_pos] = num_str[next_pos], num_str[pos]
        return int("".join(num_str))
```


