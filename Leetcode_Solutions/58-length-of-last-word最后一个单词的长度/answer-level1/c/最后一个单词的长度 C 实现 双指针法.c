![2020-01-02_13-56.png](https://pic.leetcode-cn.com/85b93f502759aac5bd4a9a92d5aa256ed4e5a698e5468627320ba8358c43ff4d-2020-01-02_13-56.png)

```c
int lengthOfLastWord(char *s) {
  // 左指针和右指针
  int left = -1, right = 0;
  // 记录单词长度，左右指针差
  int length = 0, diff = 0;

  while (s[right]) {
    // 如果右指针遇到一个空格
    if (s[right] == ' ') {
      // 并且 diff 大于 1，则认为左右指针之间形成了一个新单词
      if ((diff = right - left - 1) > 0)
        length = diff;
      // 更新左指针位置
      left = right;
    }
    right++;
  }

  // 字符串读取完毕，更新单词长度
  if ((diff = right - left - 1) > 0)
    length = diff;

  return length;
}
```