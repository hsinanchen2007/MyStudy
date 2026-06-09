* y = 1 + k + k ^ 2 + k ^ 3 + k ^ 4 + ... + k ^ x
* y = (k ^ (x + 1) - 1) / (k - 1)
* x的范围是固定的，由`1`(k = y - 1时)到`lg(y + 1) - 1`(k = 2时)
* 二分时需要转换一下思想: 由于k的范围过大(`2` ~ `y- 1`)，因此不能采用对k遍历，对x二分的方式；相反，由于x范围较小，因此采用对x遍历，对k二分就可以满足相应的时间复杂度要求了
* 此外，要注意数据范围，要用到BigInteger类或者自己添加处理逻辑
```
class Solution {
    public String smallestGoodBase(String y) {
        long num = Long.parseLong(y);
        int maxX = (int)(Math.log(num + 1) / Math.log(2) - 1);
        for(int x = maxX ; x >= 2; x--){
            long ks = 2, ke = num - 1;
            while(ks <= ke){
                long k = ks + ((ke - ks) >> 1);
                int diff = compareWithNum(x + 1, k, num);
                if(diff == 0){
                    return String.valueOf(k);
                } else if(diff < 0){
                    ks = k + 1;
                } else {
                    ke = k - 1;
                }
            }
        }
        return String.valueOf(num - 1);
    }

    private int compareWithNum(int len, long radix, long num) {
        long base = 1;
        long sum = 0;
        for (int i = 0; i < len; i++) {
            if (Long.MAX_VALUE - sum < base) {
                return 1;
            }
            sum += base;
            if (sum > num) {
                return 1;
            }
            if (Long.MAX_VALUE / base < radix) {
                base = Long.MAX_VALUE;
            } else {
                base *= radix;
            }
        }
        return sum == num ? 0 : -1;
    }
}
```