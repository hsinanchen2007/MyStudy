Java 双100%

这题有个困惑，就在于506，这个06可以翻译吗。假如可以翻译就有 fag，fg两种结果，但是假如不可以翻译就只有fag一个结果。

按照测试用例 06 是不可以计算的。
```
    public int translateNum(int num) {
        char[] eachNum = String.valueOf(num).toCharArray();
        if (eachNum.length == 1) {
            return 1;
        }

        int[] possible = new int[eachNum.length];
        possible[0] = 1;
        int i = (eachNum[0] - '0') * 10 + (eachNum[1] - '0');
        if (i < 26 && i != (eachNum[1] - '0')) {
            possible[1] = 2;
        } else {
            possible[1] = 1;
        }
        int index = 2;
        while (index < eachNum.length) {
            int i1 = (eachNum[index - 1] - '0') * 10 + (eachNum[index] - '0');
            if (i1 < 26 && i1 != (eachNum[index] - '0')) {
                possible[index] = possible[index - 2] + possible[index - 1];
            } else {
                possible[index] = possible[index - 1];
            }
            index++;
        }

        return possible[index - 1];
    }

```
