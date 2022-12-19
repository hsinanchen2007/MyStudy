# 第一种解法：常规做法 
1. 字符串全小写
2. 去除不必要的字符
3. 遍历验证索引0 ~ s/2 与 s/2 + 1 ~ s.length -1 所在的字符串是否相等
```java
public boolean isPalindrome(String s) {
        StringBuilder content = new StringBuilder();
        String lowerCase = s.toLowerCase(); // 全小写
        for (int i = 0; i < lowerCase.length(); i++) { // 保存数字or字母
            char temp = lowerCase.charAt(i);
            if ((temp >= 'a' && temp <= 'z') || (temp >= '0' && temp <= '9')) {
                content.append(temp);
            }
        }
        String finalContent = content.toString();
        // 因为去掉了不必要的字符，现在的字符串全部满足条件，只需要遍历0~当前字符串长度/2
        // 长度为单数 会忽略比较中间的字符，长度为双数 不影响比较
        for (int i = 0; i < finalContent.length()/2; i++) {
            if (finalContent.charAt(i) != finalContent.charAt(finalContent.length() - 1 - i))             {
                return false;
            }
        }
        return true;

    }
```
# 第二种解法：双指针
1. 思路就是 一个指针指向字符串头部，一个指针指向字符串尾，遇见不必要字符串跳过
```java
    public boolean isPalindrome2(String s) {
        int length = s.length(); // 遍历的长度
        String lowerCase = s.toLowerCase(); // 统一小写
        for (int i = 0; i < length; i++) {
            int lastP = 1; // 尾指针 = 长度 - lastP
            char temp = lowerCase.charAt(i);
            if (validChar(temp)) {
                while (!validChar(lowerCase.charAt(length - lastP))) { // 尾指针循环遍历跳过不满足字符
                    lastP++;
                }
                // 如果尾指针 < 头指针 或者 两个指针所对应的字符不相等
                if ((length - lastP) < i || temp != lowerCase.charAt(length - lastP)) {
                    return false;
                }
                // 修剪遍历长度
                length -= lastP;
            }
        }
        return true;
    }
    // 辅助方法，验证是否为 数字 or 字母
    private boolean validChar(char temp) {
        return (temp >= 'a' && temp <= 'z') || (temp >= '0' && temp <= '9');
    }
```

