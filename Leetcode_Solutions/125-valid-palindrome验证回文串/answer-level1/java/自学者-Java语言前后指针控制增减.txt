### 解题思路
* 前后双指针
* 字母忽略大小写
* 只识别数字是字母，空格标点符号不要

### 刷题进阶
* Character.isLetterOrDigit() 函数的使用
* 前指针的跳转
* 后指针的减少
* length减去一个索引的计算公式

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        int len = s.length();
        int front = 0;
        int back = len - (front+1);
        char anchor;
        while(front < len) {
            char f = s.charAt(front);
            if(!Character.isLetterOrDigit(f)) {
                front++;
                continue;
            }
            while(!Character.isLetterOrDigit(s.charAt(back))) {
                back--;
            }
            char b = s.charAt(back);
            //System.out.printf("%c,%c\n",f,b);
            if(Character.toLowerCase(f) != Character.toLowerCase(b)) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
}
```