使用 128 数组存放字符出现次数，最终遍历出现次数为 1 的即为首次出现的。
可优化 byte 长度（如果空间换时间的话）

### 代码
```java
public int firstUniqChar(String s) {
    char[] chars = s.toCharArray();
    byte[] bool = new byte[128]; // 如果空间换时间，可以 128 - 'a' 个长度，但是后序计算需要 -'a' 会增加字节码
    for (char aChar : chars) {
        bool[aChar] = (byte) (bool[aChar] >= 1 ? 2 : 1); // 更新次数，只要 >=1 说明历史出现过更新为 2
    }
    int length = chars.length; // 减少循环取值，也可以倒序遍历，取决于最终索引的顺序
    for (int i = 0; i < length; i++) if (bool[chars[i]] == 1) return i; // 提取次数为 1 的下标
    return -1;
}
```