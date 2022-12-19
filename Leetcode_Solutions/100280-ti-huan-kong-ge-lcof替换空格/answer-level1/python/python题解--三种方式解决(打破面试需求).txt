### 1.使用replace函数
![image.png](https://pic.leetcode-cn.com/22587a3531333acff5e4a510c320eb549ec0062c8549998cef76a97cb71f14ed-image.png)
- python内置的`replace`函数用来替换字符串中指定的字符
- 时间复杂度`O(n)`,空间复杂度`O(1)`
### 代码

```python
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s.replace(' ','%20')
```
### 2.使用循环
- 由于字符串在python中是不可变量,所以第一步将其抓换成list
- 从头到尾开始扫描,如果当前字符为空格,则用'%20'替换
- 时间复杂度`O(n**2)`,空间复杂度`O(n)`
### 代码
```
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        for i in range(len(s)):
            if s[i] == ' ':
                s[i] = '%20'
        return ''.join(s)
```
### 双指针移动+计数
![image.png](https://pic.leetcode-cn.com/92a318e5fe68287abea8d2718e9b345db18f863f681a0c25c363ff9065255752-image.png)

- 这个方法的思路是:
1. 首先遍历一次字符串`s`来统计有多少个空格
2. 假设有`m`个空格,我们需要填充的`%20`占用三个字符位置,所以需要额外开辟出`2*m`个空间
3. 将开辟出的空间链接到原字符串的后面,新的字符串命名为`s_new`设置两个指针`p1`和`p2`,初始时`p1`指向原字符串`s`的末尾,`p2`指向`s_new`的末尾
4. `p1`指针向前移动,当`p1`指向的字符不是空格时,将`p1`指向的字符复制到`p2`指向的位置,并都向前移动一位
5. 当`p1`指向的字符是空格时,`p1`向前移动一格,这时应该插入`%20`,所以`p2`向前移动三格,并在这三格中插入`%`,`2`,`0`

- 时间复杂度`O(n)`,空间复杂度`O(m)`
### 代码
```
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        s_len = len(s)
        space_count = 0
        for i in s:
            if i == ' ':
                space_count += 1
        s_len += 2 * space_count
        new_array = [' '] * s_len
        j = 0
        for i in range(len(s)):
            if s[i] == ' ':
                new_array[j] = '%'
                new_array[j+1] = '2'
                new_array[j+2] = '0'
                j += 3
            else:
                new_array[j] = s[i]
                j += 1
        return ''.join(new_array)
```

