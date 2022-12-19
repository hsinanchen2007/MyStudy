效率还可以，思路易于理解
思路:使用"&",">>"比较二进制的倒数第一个值是不是与倒数第二个值一样

例如：5 二进制为 101
解析
  1. 5(101) & 1 == 0, false
  2. 右位移1位得到 2(10)
  3. 判断,2(10) & 1 == 1, i为false
  4. 2(10) & 1 == 0, i为true
  5. 右位移1位得到 1(1)
  6. 1(1) & 1 == 0, i为false
  7. return 最后得出true

例如: 7 二进制为 111
  1. 7(111) & 1 == 0, i为false
  2. 右位移1位得到 3(11)
  3. 3(11) & 1 == 1, true,result 赋值为false,break 循环
  4. return 最后得出false
```
public boolean hasAlternatingBits(int n) {
        boolean i;
        boolean result = true;
        while (n != 0) {
            if (((n & 1) == 0)) {
                i = true;
            } else {
                i = false;
            }
            n >>= 1;
            if (i) {
                if (((n & 1) == 0)) {
                    result = false;
                    break;
                }
            } else {
                if (((n & 1) == 1)) {
                    result = false;
                    break;
                }
            }

        }
        return result;
    }
```

