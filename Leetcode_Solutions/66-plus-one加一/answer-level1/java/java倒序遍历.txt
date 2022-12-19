```
public int[] plusOne(int[] digits) {
    int p = digits.length - 1;
    int s = 1;
    while (p >= 0) {
        if (digits[p] + s > 9) {
            digits[p] = 0;
            s = 1;
        } else {
            digits[p] = digits[p] + s;
            s = 0;
        }
        p--;
    }
    if (s == 1) {
        int[] newArr = new int[digits.length + 1];
        newArr[0] = 1;
        return newArr;
    }
    return digits;

}

```
