第一步：去除噪音，只保留相关字符
第二部：收尾对比判断是否是回文

```
public boolean isPalindrome(String s) {
    if (s == null) return false;

    // 去除噪音
    char[] arr = s.toCharArray();
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < arr.length; i++) {
        char temp = Character.toLowerCase(arr[i]);
        if (('a' <= temp && temp <= 'z') || ('0' <= temp && temp <= '9')) {
            sb.append(temp);
        }
    }

    // 收尾对比判断是否是回文
    char[] newArr = sb.toString().toCharArray();
    for (int i = 0; i < newArr.length / 2; i++) {
        if (newArr[i] != newArr[newArr.length - 1 - i]) {
            return false;
        }
    }
    return true;
}
```
