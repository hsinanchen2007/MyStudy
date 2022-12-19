### 解题思路
本题思路也是来自于剑指offer
首先将整个字符串翻转一下，然后按照空格进行分词，最后对分词的内容进行再翻转。
其中有很多细节需要处理一下。
	在处理reverse函数的时候，用StringBuffer存储变量，因为String是不可变类型的，因此，不便于直接操作。
	需要考虑空格问题，如前后空格怎么处理，用index去做，如果第一个分词结果为""则直接跳过，如果是最后一个，则不append" "。

学习到了trim()方法。trim() 方法用于删除字符串的头尾空白符。
不过不知道为啥这个时间复杂度好差啊

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String str = s.trim();
        if (str.equals("")){
            return "";
        }
        String[] strList = reverse(str).split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<strList.length; i++){
            sb.append(reverse(strList[i]));
            if(i!=strList.length-1){
                sb.append(" ");
            }
        }
        return ""+sb;
    }
    private String reverse(String s){
        StringBuilder sb = new StringBuilder(s);
        int i=0, j=s.length()-1;
        while(i<j){
            char temp = sb.charAt(i);
            sb.setCharAt(i, sb.charAt(j));
            sb.setCharAt(j, temp);
            i++;
            j--;
        }
        return ""+sb;
    }
}
```