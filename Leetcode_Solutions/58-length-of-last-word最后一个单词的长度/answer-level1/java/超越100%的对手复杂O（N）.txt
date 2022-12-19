### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/0d96951b5c586c0aaf950dbe4f8a34604294cfc6f795a149171cc93987b93132-image.png)

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
                int count = 0;
        char[] chars = s.toCharArray();
        int pre = chars.length - 1;// 记录最后一个
        for ( int i = chars.length - 1; i >=0 ; i-- ) {
            if ( count == 0 && chars[i]!=' ' ){// 找到第一个不为空字符串的元素
                pre = i;
                count++;
            }

            if ( count==1 && chars[i] == ' ' ){
                return pre - i;
            }
        }
        if ( count == 1 ){
            return pre+1;
        }
        return 0;
    }
}
```