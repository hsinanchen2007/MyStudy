### 解题思路
此题比较简单，但是容易出错，刚开始考虑的是有满足条件的，从第三个元素有重新开始匹配，相当于位移了2位。但真正的是只需位移一位就可以了。
### 代码

```java
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        List<String> strList = new ArrayList<String>();
        String[] s = text.split(" ");
        int lenght = 0;
        while (lenght < s.length -2){
           if(s[lenght].equals(first) && s[lenght+1].equals(second)){
                strList.add(s[lenght+2]);
            }
            lenght++;
        }
        return strList.toArray(new String[strList.size()]); 
    }
}
```