因为先做过全排列 看见这题就莽的全排列然后排序输出了, 结果当然是超时

之后就开始🕵

一个由1234组成的四位数的全排列中位于第一位的数字的可能是
1xxx 2xxx 3xxx 4xxx
结果发现 每一种的可能性是3!
所以如果是要取第9个排列 那么这个数字必然是2xxx
由此类推可得 取第9个排列转换为取2xxx中的第3个排列 (9 - 1 * 3! 即减掉2xxx之前的所有排列个数
第二位的情况可能是
1xx 3xx 4xx
第三个排列位于3xx (每种可能是2! 所以第三个位于3xx
3 - 1 * 2!
剩下两位 1x 4x 取第一个排列
即答案为2314

下面是代码
```
class Solution {

    public Integer getFact(int n) {
        int sum = 1;
        for(int i = 1; i <= n; i ++) {
            sum *= i;
        }
        return sum;
    }

    public String getPermutation(int n, int k) {
        StringBuilder sb = new StringBuilder();
        List<Integer> list = new ArrayList<>();
        for(int i = 1; i <= n; i ++) {
            list.add(i);
        }
        for(int i = n; i >= 2; i --) {
            int fact = getFact(i);
            int count = fact / i;
            int num = (int)Math.ceil((double) k / (double)count);
            k -= count * (num - 1);
            sb.append(list.get(num - 1));
            list.remove(num - 1);
        }
        sb.append(list.get(0));
        return sb.toString();
    }
}
```
还有谁跟👴一样开始是算全排列的???