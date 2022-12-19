如果遍历结束还未return，说明数组全是9，需要在原数组的首位补一个1.
```
public int[] plusOne(int[] digits) {
        //倒序遍历
        int length = digits.length;
        for (int i = length - 1; i >= 0; i--) {
            //当前位置=9，需要特殊处理
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        //此时说明digits需要在首位补一个1
        int[] newArr = new int[length + 1];
        newArr[0] = 1;
        System.arraycopy(digits, 0, newArr, 1, length);
        return newArr;
    }
```

可优化的地方在于：首位数组补1，可简化。
