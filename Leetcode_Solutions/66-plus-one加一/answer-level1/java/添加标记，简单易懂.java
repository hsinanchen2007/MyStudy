```
    public static int[] plusOne(int[] digits) {
        if (digits == null || digits.length == 0) return digits;

        digits[digits.length - 1] = (digits[digits.length - 1] + 1) % 10;//个位加1
        int flag = digits[digits.length - 1];//如果是0，代表进位
        for (int i = digits.length - 2; i >= 0; i--) {
            if (flag == 0) {
                digits[i] = (digits[i] + 1) % 10;
                flag = digits[i] % 10;
            }
        }

        if (digits[0] == 0) {
            int[] arr = new int[digits.length + 1];
            arr[0] = 1;
            return arr;
        }

        return digits;
    }
```
