### 解题思路 - 临时数组进行拷贝的方法
[leetcode-189](https://leetcode-cn.com/problems/rotate-array/)

对比旋转后的数组和旋转前的数组，可以看出本质上就是把前k个字符，挪到了字符串后面。

- 于是我们可以使用辅助数组，
- 先把原始字符串后n-k个字符填充进去，
- 再把原始字符串前k个字符填充进去，

这个方法的时间复杂度是O(n),n是数组长度，使用了一个临时数组，空间复杂度是O(n)。


### 代码

```golang
func reverseLeftWords(s string, n int) string {
  // 字符串长度赋值给m，n对字符串长度取模，定义游标i
  m, k, i := len(s), n%len(s), 0 
  // 定义辅助数组
  t := make([]byte, m)
  // 先把原字符串中后面m-k个字符拷贝到临时字符数组
  for j:=k;j<m;j++{
    t[i] = s[j]
    i++
  }
  // 再把原字符串前面的k个字符拷贝到临时字符数组
  for j:=0;j<k;j++{
    t[i] = s[j]
    i++
  }
  return string(t)
}
```