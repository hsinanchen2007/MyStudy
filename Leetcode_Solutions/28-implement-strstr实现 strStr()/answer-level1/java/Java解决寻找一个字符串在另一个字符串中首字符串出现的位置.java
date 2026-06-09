### 解题思路
1.首先处理特殊的needle为空的情况
2.使用String的contains()方法判断haystack中是否存在neddle
3.定义一个变量用来记录返回值
4.haystack中存在needle,使用一个自定义的String类型值调用replace()替换掉needle，得到一个新字符串，再使用indexOf()获取替换后新字符串中，自定义字符串在新字符串中的位置，就得到needle存在haystack中的位置。将调用indexOf()返回的值赋值给自定义变量用来返回
5.haysack中不存在needle,将-1赋值给自定义变量，用来返回

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
         if("".equals(needle) || null == needle ){
            return 0;
        }
        int m = 0;
        if(haystack.contains(needle)){
          String temp =   haystack.replace(needle,"1");
            m = temp.indexOf("1");
        }else {
            m = -1;
        }


        return m;
    }
}
```