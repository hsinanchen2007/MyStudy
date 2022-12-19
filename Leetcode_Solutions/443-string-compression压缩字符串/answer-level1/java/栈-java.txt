```java
public int compress(char[] chars) {
    if (chars == null || chars.length == 0)
        return 0;
    // top 栈顶指针, count 连续字符的个数
    int top = -1, count = 1;
    // 从第二个字符开始
    for (int i = 1; i < chars.length; i++) {
        // 如果与前一个字符相等, 计数加1
        if (chars[i - 1] == chars[i]) {
            count++;
        } else {
            // 如果与前一个字符不等, 将前一个字符入栈
            chars[++top] = chars[i - 1];
            // 如果连续个数大于1, 需要将计数转为字符串后, 再将字符依次入栈
            if (count > 1) {
                for (char c : Integer.toString(count).toCharArray()) {
                    chars[++top] = c;
                }
                // 计数重置为1
                count = 1;
            }
        }
    }
    // 处理最后一个字符
    chars[++top] = chars[chars.length - 1];
    if (count > 1) {
        for (char c : Integer.toString(count).toCharArray()) {
            chars[++top] = c;
        }
    }
    // top + 1 为总长度
    return top + 1;
}
```
