### 解题思路
此处撰写解题思路
看到数列，有点像*斐波那契*然后我就想到了递归
再由双指针来判断相同的字符和计数
输入的n主要是用来判断演化次数
### 代码

```java
class Solution {
    public static String countAndSay(int n) {
        String s="1";
        if(n<=1) return "1";
        for(int i=0;i<n-1;i++){//递归次数
            s=count(s);
        }
        return s;
    }
    public static String count(String s){
        StringBuilder ret=new StringBuilder();
        int count=0;
        int head=0;
        int end=0;
        while (end<s.length()){
            while (s.charAt(head)==s.charAt(end)){
                count++;
                end++;
                if(end==s.length())break;//防止下标越界
            }
            ret.append(count).append(s.charAt(head));
            head=end;//开始下一段字符判断
            count=0;
        }
        return ret.toString();
    }
}
```