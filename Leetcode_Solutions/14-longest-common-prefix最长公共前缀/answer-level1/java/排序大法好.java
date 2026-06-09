# 详细内容可以参考链接：[Leetcode 14. 最长公共前缀](https://www.yuque.com/tiantianshuo/coding/longest-common-prefix)

## 思路1：两两取公共前缀
每次取2个字符串，获得公共前缀。然后把公共前缀再次当做新的字符串放入数组，进行比较。直到数组中只剩下一个字符串时，该字符串就是最长公共前缀。

### 代码
```java
public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) {
        return "";
    }
    if (strs.length == 1) {
        return strs[0];
    }
    // 此处为了方便，使用了LinkedList
    LinkedList<String> linkedList = new LinkedList<>();
    for (String str : strs) {
        linkedList.addFirst(str);
    }
    return longestCommonPrefix(linkedList);
}
private String longestCommonPrefix(LinkedList<String> linkedList) {
    while (linkedList.size() > 1) {
        // 取出2个字符串
        String s1 = linkedList.removeFirst();
        String s2 = linkedList.removeFirst();
        // 获取公共前缀
        StringBuilder commonPrefix = new StringBuilder();
        for (int i = 0; i < s1.length() && i < s2.length(); i++) {
            if (s1.charAt(i) == s2.charAt(i)) {
                commonPrefix.append(s1.charAt(i));
            } else {
                break;
            }
        }
        
        // 公共前缀加入数组
        linkedList.addLast(commonPrefix.toString());
    }
    return linkedList.get(0);
}
```

该方法的时间复杂度是(O2), 虽然比暴利破解O(n3)的解法好，但是依旧不够完美。

## 思路2：排序
将字符串排序，然后取第一个字符串和最后一个字符串的公共前缀即可。（排序算法直接使用库函数，获得最优的排序时间复杂度）

### 代码
```java
public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) {
        return "";
    }
    if (strs.length == 1) {
        return strs[0];
    }
    // 排序
    Arrays.sort(strs);
    String s1 = strs[0];
    String s2 = strs[strs.length - 1];
    StringBuilder commonPrefix = new StringBuilder();
    for (int i = 0; i < s1.length() && i < s2.length(); i++) {
        if (s1.charAt(i) == s2.charAt(i)) {
            commonPrefix.append(s1.charAt(i));
        } else {
            break;
        }
    }
    return commonPrefix.toString();
}
```