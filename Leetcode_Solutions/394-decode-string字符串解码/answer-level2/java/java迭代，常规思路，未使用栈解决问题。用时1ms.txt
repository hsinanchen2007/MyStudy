### 解题思路
①   找到第一对匹配的括号开始和结束的索引位置
②   从"["括号的开始位置向前扫描，找到数字出现的起始坐标
③   把出现在数字之前的字符复制到StringBuilder中
④   复制括号中的字符到StringBuilder中
⑤   复制"]"括号后的字符到StringBuilder中
⑥   s赋值为StringBuilder中的字符串，并将StringBuilder清空，重复上述过程，指导s字符串中找不到括号为止；

### 代码

```java
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        while (s.indexOf("[") != -1) {  //当字符串中未不再有括号时，说明已经编码完成，退出循环

            // 记录s字符串中[]开始和结束的索引；
            int equoteStart = 0, equoteEnd = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '[') equoteStart = i;
                else if (s.charAt(i) == ']') {equoteEnd = i; break;}
            }

            //在[括号的索引之前寻找重复数字出现的起始坐标
            int numStart = equoteStart - 1;
            while (numStart >= 1 && Character.isDigit(s.charAt(numStart - 1))) numStart--;

            //在StringBuilder中复制s中数字出现的字符
            sb.append(s.substring(0, numStart));

            //重复的次数
            int times = Integer.valueOf(s.substring(numStart, equoteEnd));
            for (int i = 0; i < times; i++)
                sb.append(s.substring(equoteStart + 1, equoteEnd));

            //最后将]括号后面的复制到StringBuilder中
            if (equoteEnd < s.length() - 1)
                sb.append(s.substring(equoteEnd + 1, s.length()));

            s = sb.toString(); // 字符串s重新赋值
            sb = new StringBuilder(); //清空StringBuilder里面的内容
        }
        return s;
    }
```