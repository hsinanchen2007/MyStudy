### 解题思路
StringBuilder类是字符串可变对象类，进行一次遍历：
&emsp;&emsp;如果当前字符c==' ',在StringBuilder对象后增加"%20";否则，直接增加该字符。
时间复杂度O(n),空间复杂度O(n)

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuilder ret = new StringBuilder();
        for(char c : s.toCharArray()){
            if(c ==' '){
                ret.append("%20");
            }
            else{
                ret.append(c);
            }
        }
        return ret.toString();
    }
}
```