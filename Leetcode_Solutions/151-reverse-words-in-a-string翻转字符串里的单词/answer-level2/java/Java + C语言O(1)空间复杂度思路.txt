### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/6d0ce39a27a540e34903219fa3c80a273f32d6a830dab86dc09c44d01f9945f5-%E5%9B%BE%E7%89%87.png)
**直接split，其实这里可以用正则\\s+，我用的空格，所以判断了一下长度**

**O(1)的空间思路是单词内部倒置，再整体倒置**
**因为我们知道，一个字符串的倒置，只需要用一个空间进行头尾交换即可。**
```
char temp = s[i]
s[i] = s[j]
s[j] = temp
```
举个例子：
        **hello world**
        **先单词内部倒置**
        **olleh dlrow**
        **再整体倒置**
        **world hello**

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(int i = words.length - 1; i >= 0; i --){
            if(words[i].length() > 0) sb.append(words[i].trim() + " ");
        }
        return sb.toString().trim();
    }
}
```