```
public static int[] plusOne(int[] digits) {
        int len = digits.length;

        int counter=0;
        for (int i = 0; i < len; i++) {
            if (digits[i] == 9) {
                counter++;
            }
        }
        //999  9999
        if (counter == len) {
            int[] res = new int[len + 1];
            res[0] = 1;
            return res;
        }

        recursive(digits, len - 1);
        return digits;
    }

    private static void recursive(int[] digits,int index) {
        if (digits[index] != 9) {
            digits[index] = digits[index]+1;
        }else{
            digits[index]=0;
            recursive(digits,index-1);
        }
    }
```

特殊情况（999，9999）需单独处理，

其他情况，使用尾递归实现
