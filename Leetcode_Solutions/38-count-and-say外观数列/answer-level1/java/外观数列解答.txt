### 解题思路
序列n由序列n-1得到，首先从第一个序列开始，有频繁的对字符串操作，必须使用单线程的动态字符串StringBuilder类型，再转化为String类型进行返回

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        StringBuilder str = new StringBuilder();
        String preStr = "1";//最开始的字符串
        for(int j = 1; j < n; j++){//从1遍历到n-1，第n个序列由第n-1个序列得到
            str.setLength(0);//清空动态字符串
            char c = preStr.charAt(0);//取上一个字符串的第一个字符
            int cnum = 1;
            for(int i = 1; i < preStr.length(); i++){//遍历上一个字符串，从第二个字符开始
                char cnext = preStr.charAt(i);
                if(c == cnext){
                    cnum++;
                }else{
                    str.append(cnum).append(c);
                    cnum = 1;//前面字符与后面字符不等，则重新统计数目
                    c = cnext;//更新对比的字符
                }

            }
            str.append(cnum).append(c);//cnext遍历完就没有赋值，在字符串遍历结束时必须加
            preStr = str.toString();//将Stringbuilder转化为String
        }
        return preStr;
    }
}
```