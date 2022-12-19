### 解题思路
执行用时 :
**1 ms**
, 在所有 java 提交中击败了
**100.00%**
的用户
内存消耗 :
**34.6 MB**
, 在所有 java 提交中击败了
**96.53%**
的用户

### 代码

```java
class Solution {
    public String toGoatLatin(String S) {
        //  记录结果
        StringBuilder result = new StringBuilder();
        char[] chars = S.toCharArray();
        //  单词索引
        int count = 1;
        //  是否是单词开头
        boolean start = true;
        //  记录辅音字符索引
        int temp = -1;
        //  遍历字符数组
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            //  单词开头处理
            if (start) {
                switch (c) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        //  元音直接添加
                        result.append(c);
                        break;
                    default:
                        //  辅音记录索引即可
                        temp = i;
                }
                //  单词开头置为false
                start = false;
            } else if (c == ' ') { //  单词结束处理
                //  是否以辅音开头
                if (temp != -1) {
                    //  添加辅音字符
                    result.append(chars[temp]);
                    temp = -1;
                }
                result.append('m');
                result.append('a');
                //  添加单词索引个数的 a
                for (int j = 0; j < count; j++) {
                    result.append('a');
                }
                //  单词索引+1
                count++;
                //  添加单词空格
                result.append(' ');
                //  下一个字符是否为单词开头置为true
                start = true;
            } else {
                //  其他单词字符直接添加即可
                result.append(c);
            }
        }
        //  需要对最后一个单词进行额外处理
        if (temp != -1) {
            result.append(chars[temp]);
        }
        result.append('m');
        result.append('a');
        for (int j = 0; j < count; j++) {
            result.append('a');
        }
        return result.toString();
    }
}
```