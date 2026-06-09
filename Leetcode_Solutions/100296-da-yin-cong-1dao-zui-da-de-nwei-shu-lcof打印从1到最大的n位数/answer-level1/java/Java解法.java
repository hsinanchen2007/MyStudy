public int[] printNumbers(int n) {
    int len = (int) Math.pow(10, n) - 1;
    int[] res = new int[len];
    for (int i = 0; i < len; i ++) {
        res[i] = i + 1;
    }
    return res;
}
我没明白弄这样一个题是啥意思。。。