### 解题思路
此处撰写解题思路
两轮递归处理，第一轮递归获取第n-1的描述串，第二个递归把n-1的描述串翻译，作为第n的描述串。
事实证明递归开销是真的大
### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if(n==1) return "1";
        String pre = countAndSay(n-1);
        return discribeToSay(pre);
    }
    public String discribeToSay(String pre)
    {
        String res = "";
        int count = 1;
        if(pre=="") return res;
        char temp = pre.charAt(0);
        int i = 1;
        for(; i < pre.length();i++)
        {
            if(pre.charAt(i)==temp) count++;
            else
            {
                res+=String.valueOf(count);
                res+=temp;
                res+=discribeToSay(pre.substring(i));
                return res;
            }
        }
        if(i==pre.length())
        {
            res+=String.valueOf(count);
                res+=temp;
        }
        return res;
    }
}
```