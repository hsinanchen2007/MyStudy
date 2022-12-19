```
public int atMostNGivenDigitSet(String[] D, int N) {
    String strN = String.valueOf(N);
    //N的位数digits
    int digits = String.valueOf(N).length();
    int nums = D.length;
    //count1:位数小于N的位数的正整数的数目
    int count1 = 0;
    for (int i = 1; i <= digits - 1; i++) {
        count1 += Math.pow(nums, i);
    }

    //count2:位数等于N的位数且大小小于N的正整数的数目
    int count2 = 0;
    int i;
    //遍历N的每一位
    for (i = 0; i < digits; i++) {
        int digit = strN.charAt(i) - '0';
        //数组D中比N第i位小的数字的个数
        long countSmaller = Arrays.stream(D).mapToInt(x -> Integer.valueOf(x))
                .filter(x -> x < digit).count();
        count2 += countSmaller * Math.pow(nums, digits - i - 1);
        //N第i位数不在数组D中，退出循环
        if (Arrays.stream(D).mapToInt(x -> Integer.valueOf(x))
                .filter(x -> x == digit).count() == 0) {
            break;
        }
    }

    //count3:位数等于N的位数且大小等于N的正整数的数目
    int count3 = 0;
    if (i == digits) {
        count3 = 1;
    }

    return count1 + count2 + count3;
}
```
