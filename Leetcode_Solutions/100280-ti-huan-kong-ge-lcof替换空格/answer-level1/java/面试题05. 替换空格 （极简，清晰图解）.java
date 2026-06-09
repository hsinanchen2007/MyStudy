### 解题思路：


> 在 Python 和 Java 等语言中，字符串都被设计成不可变的类型，即无法直接修改字符串的某一位字符，需要新建一个字符串实现。

- **Python 解法流程：**
  1. 初始化一个 list ，记为 `res` ；
  2. 遍历列表 `s` 中的每个字符 `c` ：
      - 当 `c` 为空格时：向 `res` 后添加字符串 `"%20"`；
      - 当 `c` 不为空格时：向 `res` 后添加字符 `c` ；
  3. 将列表 `res` 转化为字符串并返回。

- **Java 解法流程：**
  1. 初始化一个 StringBuilder ，记为 `res` ；
  2. 遍历字符串 `s` 中的每个字符 `c` ：
      - 当 `c` 为空格时：向 `res` 后添加字符串 `"%20"`；
      - 当 `c` 不为空格时：向 `res` 后添加字符 `c` ；
  3. 将 `res` 转化为 String 类型并返回。

#### **复杂度分析：**

- **时间复杂度 $O(N)$ ：** 遍历使用 $O(N)$ ，每轮添加（修改）字符操作使用 $O(1)$ ；
- **空间复杂度 $O(N)$ ：** Python 新建的 list 和 Java 新建的 StringBuilder 都使用了线性大小的额外空间。

<![Picture1.png](https://pic.leetcode-cn.com/480b60e389589b7f732c28edc60c82f260ac86aef55970e767fc22c3e33b5e0f-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/64fa05c818722c11cb4b8751d487e179fb18c2f079428a7c6dc813b7220a7994-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/a0352db120da6997f2675200f9328e57bb9fba2279f77d70ad488030bbce0aae-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/d712bbafefabab45711ba5d14e8372671797bf37376f8efdee4562093e285b28-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/3121ffccd8ab8339b583c6b49b5da10b8c981443d0a26873dab33415373305d3-Picture5.png)>

#### 代码：

```python []
class Solution:
    def replaceSpace(self, s: str) -> str:
        res = []
        for c in s:
            if c == ' ': res.append("%20")
            else: res.append(c)
        return "".join(res)
```

```java []
class Solution {
    public String replaceSpace(String s) {
        StringBuilder res = new StringBuilder();
        for(Character c : s.toCharArray())
        {
            if(c == ' ') res.append("%20");
            else res.append(c);
        }
        return res.toString();
    }
}
```