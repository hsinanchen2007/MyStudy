### 解题思路
题没有读太懂，看着结果大体写了一下，提交了，还真过了。。。就是执行时间太长了，准备看看大神的解法。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
       //先把String数组转换成set去重，准备两个同样的set
        Set<String> wordSet = new HashSet<>(Arrays.asList(words));
        Set<String> wordSetCopy = new HashSet<>(Arrays.asList(words));
        StringBuffer sb = new StringBuffer();
      
          for (String s : wordSet) {
              //循环遍历set,如果有以单词结尾且长度不等的字符串，就从第二个set中移除
            wordSetCopy.removeIf(s1 -> s.endsWith(s1) && s.length() !=                  s1.length());
        }
        wordSetCopy.forEach(
                (k)->{
                  sb.append(k).append("#")  ;
                }
        );
        return sb.toString().length();
    }
}
```