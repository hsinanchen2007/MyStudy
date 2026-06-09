### 解题思路
利用String类型的indexOf方法和lastIndexOf方法，

循环判断字符串中各字符第一次和最后一次出现的索引，不同则为重复字符。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        boolean flag = true;
        for(int i = 0;i < astr.length();i++){
        	if(astr.indexOf(astr.charAt(i))!=astr.lastIndexOf(astr.charAt(i))){
        		flag = false;
                break;
        	}
        }
        return flag;
    }
}
```