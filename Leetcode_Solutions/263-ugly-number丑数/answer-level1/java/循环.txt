从大到小，不断除下去，最后大于5即含其他质数、即非丑数
```
public class UglyNumber {

    /**
     * 思路：从大到小，不断地除下去最后＞5即不是丑数
     */
    public boolean isUgly(int num) {
        if (num < 0) return false;
        int[] baseArr = new int[]{1, 2, 3, 5};
        int i = 3;
        while (i > 0) {
            if (num % baseArr[i] != 0) {
                i--;
                continue;
            }
            num /= baseArr[i];
        }
        if (num > 5) return false;
        return true;
    }
}
```
