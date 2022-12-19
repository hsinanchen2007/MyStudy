首先放上我个人的代码，思路是参考别人的，实现的很慢仅供理解
```
public String convertToTitle(int n) {
    List<Integer> list = new ArrayList<>();
    do {
        int i = n % 26;
        if (i == 0) {
            i = 26;
            n--;
        }
        list.add(i);
        n = n / 26;
    } while (n > 0);
    Collections.reverse(list);
    StringBuilder builder = new StringBuilder();
    for (int num : list) {
        builder.append(helper(num));
    }
    return builder.toString();
}

public char helper(int num) {
    return (char) ('A' + num - 1);
}
```
一开始我也很不理解为何每次循环要n--，现在提供一个逆向的思考方法：
我们都很熟悉十进制，假如现在要删除十进制的0，就是不要这个数字了，但为了维持十进制，添加一个数字x，定义x为老十进制中的10
那我们开始数数，1 2 3 4 5 6 7 8 9 x 11 12 .. 17 18 19
问题来了，下一位是多少呢？
显然是 1x
对比题目，也是一个没有0的26进制，其实0对于进制来说很重要，不少计算都少不了，但是没有0，我们也许进行很多运算都会变成另一种数学，但这并不妨碍我们“数数”
在循环中遇到26的时候，不能按照有0的进制进位，必需将z替换进去，其实这是一种借位的思想，有借就有还，所以再下一步的运算中n必需减一。
详细的证明可以参考高赞答案...