### 解题思路
//循环 把所有的字符加入到新容器中，直到出现重复字符，进行截取操作

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {

    if(s==null || s.length()==0)
    {
      return 0;
    }
    char[] chars =  s.toCharArray();
    String temp = "";
    String maxTemp = "";
    
    for(int i=0;i<chars.length;i++)
    {
      char current = chars[i];
      if(temp.contains(current+""))
      {
        temp = temp.substring(temp.indexOf(current)+1, temp.length());
        temp += current;

      }else {
        temp += current;
      }


      if(temp.length()>maxTemp.length()) {
        maxTemp = temp;
      }
    }

    return maxTemp.length();
  }
}
```