
-   首先从右向左寻找，找到第一个逆序
-   然后从逆序位置向右寻找，找出仅次于逆序数字的位置进行交换即可

```
[3,2,1]
第一个逆序位置为1，数字是2，从逆序位置向向右寻找，仅次于数字2的位置
交换的到结果：
[3,1,2]

=======================================================
[1,9,4,6,7]
逆序对是[9,4]，位置为1，向右寻找仅次于当前数字的那个位置，也就是7对应的位置
得到结果
[1,7,4,6,9]

```



```python
class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        length = len(A)
        left = length

        for i in range(length - 1, 0, -1):
            if A[i] < A[i - 1]:
                left = i - 1
                break
        if left < length:
            right = left + 1
            for i in range(left + 2, length):
                if A[left] > A[i] > A[i - 1]:
                    right = i
            A[left], A[right] = A[right], A[left]

        return A
```


