
1、长度不同，返回False
2、两个字符串中元素数量不同，返回False
3、交换次数在两次或两次以上，返回False

我在这里做了一个统计函数count_list做判断,或者使用标准库collection中的Counter

```
# from collections import Counter

def count_list(A):
    dict = {}
    for i in A:
        if i in dict.keys():
            dict[i] += 1
        else:
            dict[i] = 1
    return dict

def change(A,B):
    # 长度不同，False
    # 元素不同，False
    # 交换两次及两次以上，False
    if len(A) == len(B):
        if count_list(A) == count_list(B): # Counter(A) == Counter(B)
            if [(a==b) for a,b in zip(A,B)].count(False) == 2:
                return True
            else:
                return False
        else:
            return False
    else:
        return False
```
