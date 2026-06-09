### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String toLowerCase(String str) {
        StringBuilder s =  new StringBuilder();
        for(char c:str.toCharArray()){  //增强for（）循环
            if(c>=65 && c<=90)
                c+=32;
            s.append(c);
        }
        return s.toString();
        //return str.toLowerCase();     //也可以直接用函数实现
    }
}
```