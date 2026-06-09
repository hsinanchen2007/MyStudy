### 解题思路
首先：题目上的不存在最后一个单词表示字符串为null或者''
其次，不管末尾有多少个空格都需要去尾
最后，倒序查一下最后一个单词长度就AC啦。
代码理解：我没有进行字符的增删改查操作。使用下标进行处理

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {

        if (s == null || "".equals(s)){
            return  0;
        }
        //如果不存在最后一个单词，请返回 0 。表示的竟然值末尾为 ' ' 不对。竟然表示s==null;md
        char[] c = s.toCharArray();
        int count = 0, length = c.length;

        //先去尾
        for (int i = length - 1; i>= 0; i --){
            if (c[i] == ' '){
                length --;
            }else {
                break;
            }
        }

        //再计算
        for (int i = length - 1; i>=0 ;i--){
            if (c[i] == ' '){
                break;
            }else {
                count ++;
            }
        }

        return count;
    }

}
```