
测试数据: {1,26,27,28,52,53}


本题的本质是进制之间的转换，正常情况下我们每次取余数拼接后逆序一下即可。

```
public String convertToTitle(int n) {
    String AZ = "#ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char[] CZ = AZ.toCharArray();

    StringBuilder sb = new StringBuilder();

    while (n > 0) {
        sb.append(CZ[n % 26]);
        n = n / 26;
    }

    return sb.reverse().toString();
}
        
```
但由于我们多加了一个 '#' 字符，返回结果是 A,A#,AA,AB,B#,BA 

我们来看 26 这个结果 'A#' 本质上是等价于 'Z' 的，

把 '#' 单独处理一下即可

```
public String convertToTitle(int n) {
    String AZ = "#ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char[] CZ = AZ.toCharArray();

    StringBuilder sb = new StringBuilder();

    while (n > 0) {
        if (n % 26 == 0) {
            sb.append('Z');
            n = n / 26 - 1;
        } else {
            sb.append(CZ[n % 26]);
            n = n / 26;
        }
    }

    return sb.reverse().toString();

}
```
