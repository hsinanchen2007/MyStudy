1. 方法很土，但是很容易理解
2. 第一次写题解，见笑了~~
```
class Solution{
    public static List<Integer> circularPermutation(int n, int start) {
        List<Integer> list = new ArrayList<>();
        list.add(start);
        for (int i = 1; i < (1 << n); i++) {
            //将start转为二进制
            start = getBinaryCode(start);
            //加一取余操作后转为格雷码
            start = (start + 1) % (1 << n);
            start = getGrayCode(start);
            list.add(start);
        }
        return list;
    }

    private static int getBinaryCode(int grayCode) {
        int binaryCode = grayCode;
        grayCode >>= 1;
        while (grayCode != 0) {
            binaryCode ^= grayCode;
            grayCode >>= 1;
        }
        return binaryCode;
    }

    private static int getGrayCode(int binaryCode) {
        return binaryCode ^ (binaryCode >> 1);
    }
}
```


