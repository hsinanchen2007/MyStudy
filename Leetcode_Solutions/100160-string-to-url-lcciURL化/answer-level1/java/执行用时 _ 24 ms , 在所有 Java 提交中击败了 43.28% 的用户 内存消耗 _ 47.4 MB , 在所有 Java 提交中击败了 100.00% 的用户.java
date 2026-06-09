### 解题思路
这题思路不难，只说一个注意点，不要用String来存储结果，否则结果会溢出，建议使用StringBuilder.因为String的结果每发生一次变化都是一个新的String类，而StringBuilder每次都是对自己的对象进行改变，不会生成新的对象。

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
       StringBuilder sb = new StringBuilder();
       char[] arr = S.toCharArray();
       for(int i = 0;i<length;i++) {
           if(arr[i]==' ') {
               sb.append("%20");
               continue;
           }
           sb.append(arr[i]);
       }

       return sb.toString();


    }
}
```