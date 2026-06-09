### 解题思路
1. 使用递归的方法，将问题分解。
2. 首先使用StringBuffer拼接字符串，并将s转化为字符数组用于遍历。
3. start表示当前字符串的遍历位置，count表示重复次数，num用于匹配[]（当遇到类似2[2[c]]时，将2[c]提取出来）。flag标记遇到数字，用于提取数字前的字符。
4. 具体步骤是，首先将字符串开始的非数字字符放入StringBuffer中，然后提取重复次数count，然后将后面[]中的内容提取到，进行递归。将递归返回的字符串重复count次放入StringBuffer中，并重制flag。最后判断start是否小于length，如果小于，说明最后还有字符串（类似2[c]d中的d），将其放入StringBuffer并返回结果。

### 代码

```java
class Solution {
    public String decodeString(String s) {
        if(s == null || s.length() == 0) return s;
        StringBuffer sb = new StringBuffer();
        char[] charS = s.toCharArray();

        int start = 0, count = 0, length = s.length(), num = 0, flag = 0;
        String str = "";

        for(int i = start; i < length; i++){
            if(charS[i] - '0' < 10 && charS[i] - '0' > -1 && num == 0 && flag == 0){
                sb.append(s.substring(start, i));
                start = i;
                flag = 1;
            }
            else if(charS[i] == '['){
                if(num == 0){
                    count = Integer.parseInt(s.substring(start, i));
                    start = i + 1;
                }
                num++;
            }
            else if(charS[i] == ']'){
                if(num == 1){
                    str = decodeString(s.substring(start, i));
                    for(int j = 0; j < count; j++) sb.append(str);
                    start = i + 1;
                    flag = 0;
                }
                num--;
            }
        }
        if(start < length) sb.append(s.substring(start));
        return sb.toString();
    }
}
```