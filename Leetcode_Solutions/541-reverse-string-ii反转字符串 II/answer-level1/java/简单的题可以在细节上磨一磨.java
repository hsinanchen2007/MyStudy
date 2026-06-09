- 提前算好 `step = 2 * k`
- 遍历的索引 `i` 直接用 `left`
- 交换字符使用位运算
```java
public String reverseStr(String s, int k) {
    char[] arr = s.toCharArray();
    for (int left = 0, step = 2 * k; left < arr.length; left += step) {
        int right = Math.min(arr.length - 1, left + k - 1);
        swap(arr, left, right);
    }
    return new String(arr);
}
private void swap(char[] arr, int left, int right) {
    while (left < right) {
        arr[left] ^= arr[right];
        arr[right] ^= arr[left];
        arr[left++] ^= arr[right--];
    }
}
```
