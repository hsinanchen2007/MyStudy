注意的点：
- 使用`StringBuilder`存储结果
- 使用`HashMap`保存每次进行除运算的结果的位置
- 有可能出现溢出情况（转换成Long）
- 存在负数的情况，注意判断正负号

```Java
public String fractionToDecimal2(int numerator, int denominator) {
    if (numerator == 0) return "0";
    StringBuilder ret  = new StringBuilder();
    HashMap<Long, Integer> map = new HashMap<>();
    if ((numerator < 0 ) ^ (denominator < 0)) ret.append("-");  // 使用异或判断异号
    long n = Math.abs((long) numerator);
    long d = Math.abs((long) denominator);
    ret.append(n/d);
    n = n % d;
    if (n == 0) return ret.toString();  // 可以整除
    ret.append(".");
    while (!map.containsKey(n)) {
        map.put(n, ret.length());  // 注意此处
        n = n * 10;
        ret.append(n/d);
        n = n % d;
        if (n == 0) return ret.toString();
    }
    // 存在循环部分(找到出现循环的位置，添加括号)
    ret = ret.insert(map.get(n), "(").append(")");
    return ret.toString();
}
```

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！