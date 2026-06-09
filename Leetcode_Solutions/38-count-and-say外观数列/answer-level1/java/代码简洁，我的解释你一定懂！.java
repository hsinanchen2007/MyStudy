题意理解如下：
```
1     （读作：1个1，  -> 11就是下一行）
11    （读作：2个1，  -> 21就是下一行）
21    （读作：1个2，1个1，-> 1211就是下一行）
1211  （读作：1个1，1个2，2个1，-> 111221就是下一行）
111221（读作：3个1，2个2，1个1，-> 312211就是下一行）
312211（...）
```

通过上面的模拟过程，应该可以很好地理解本题的题意了，代码就是对这个过程的翻译，如下：

```java
public String countAndSay(int n) {
    String prevLine = "1";
    int k = 1;
    while (k < n){
        // 根据前一行推出当前这一行 
        StringBuilder currLine = new StringBuilder();
        char[] s = prevLine.toCharArray();
        int i = 0, len = s.length;
        while(i < len) {
            char c = s[i];
            int count = 0;
            // c 为当前的数字，count 统计该数字“不间断”的出现了几次
            while (i < len && c == s[i]) {
                i++;
                count++;
            }
            // 将统计结果记录下来，即有 count 个 c。完全就是对之前理解过程的翻译
            currLine.append(count).append(c);
        }
        // 将当前行赋值给 preLine，进入下一次迭代
        prevLine = currLine.toString();
        k++;
    }
    return prevLine;
}
```

