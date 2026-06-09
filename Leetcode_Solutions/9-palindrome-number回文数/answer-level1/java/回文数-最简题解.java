# 回文数

## 分析

1. 因为是回文数，不用考虑整数溢出,但是测试非回文数的时候，还是会溢出
2. 数字计算会溢出，因此要判断res和of的大小关系（即确定再添 1 位是否会溢出）。
2. 如果输入int值的是负数，肯定不是回文数，直接返回`false`
3. 将输入的int值翻转，为当前数取对10的余数，再依次填入res尾部

## 实现

```java []
class Solution {
    int res = 0;
        int of = Integer.MAX_VALUE / 10;
        // 定义临时变量保存x值
        int temp = x;
        // 负数直接返回false
        if (x < 0) {
            return false;
        }
        // 翻转
        while (x != 0) {
            if (Math.abs(res) > of) {
                return false;
            }

            res = res * 10 + x % 10;
            x /= 10;

        }

        if (res == temp) {
            return true;
        } else {
            return false;
        }
}
```

