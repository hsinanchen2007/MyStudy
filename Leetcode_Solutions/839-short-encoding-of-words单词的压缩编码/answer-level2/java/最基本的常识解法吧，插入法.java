### 解题思路
此处撰写解题思路
这个题其实就观察某一段长的字符串尾部包含另外一串短的字符串不。
为此我们可以先把数组按字符串长度降序排列，随后把每个字符串末尾加上“#”号
因为加上“#”号后我们便可以用JAVA自带的包含与否判断，并且避开类似 cnzlike 下一个单词是 cnz 或者 nz之类的情况
这应该是学JAVA中大家都接触过的插入法。
随后只需要把不包含的字符串+在一起 再计算出长度便是，这是一个基本的方法 但效率不高。
### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words,(s1,s2) -> s2.length() - s1.length());//字符串数组按长度 降序排列
        String[] temp = new String[words.length];// 创建新的数组用于存放每串字符串+#后的字符串
        String S = "";
        for(int i=0;i<words.length;i++){//存放新的字符串
            S=words[i]+"#";
            temp[i] = S;
        }
        String l = "";
        for(int i=0;i<temp.length;i++){//遍历新的字符串 如果不包含则添加在字符串末尾
            if(!l.contains(temp[i])){
                l += temp[i];
            }
        }
        return l.length();
    }
}
```