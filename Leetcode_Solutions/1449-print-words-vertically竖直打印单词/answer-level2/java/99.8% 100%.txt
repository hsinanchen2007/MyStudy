### 解题思路
![111.png](https://pic.leetcode-cn.com/b041ec1f4d11ad34030c1eb29ad174b035a51d46835afcaf87448cdbb931cf73-111.png)



### 代码


```java
class Solution {
    public List<String> printVertically(String s) {
        List<String> res=new ArrayList<>();//用于返回结果
        String []words=s.split(" ");
        int max=0;//用语存储单词的最长长度
        for (String i:words)
            max= Math.max(max,i.length());
        for (int j = 0; j < max; j++) {
            String str="!";//因为后面用到trim，但是不能去掉前面的空格，所以加个符号防去掉前面空格
            for (String word:words) {
                if (j + 1 > word.length()) {//如果超出了单词长度就加空格
                    str+=" ";
                }
                else {//没超就把字母写入
                    str+=word.charAt(j);
                }
            }
            res.add(str.trim().substring(1));//把新字符串一个个加到list
        }
        return res;
    }
}
```