- 避免构造字符串不断拼接
- 避免强制转换
```java
public String toLowerCase(String str) {
    char[] arr = str.toCharArray();
    for (int i = 0; i < arr.length; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] += 'a' - 'A';
        }
    }
    return String.valueOf(arr);
}
```
