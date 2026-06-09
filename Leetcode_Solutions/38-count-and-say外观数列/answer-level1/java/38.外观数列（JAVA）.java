### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了98.81%的用户内存消耗 :34.2 MB, 在所有 Java 提交中击败了56.99%的用户

递归每一项，并且强烈建议使用**StringBuilder**，频繁操作String使用普通拼接效率极低。
1. 一次递归遍历一项字符串。
2. 每次遍历可得到数字计数及数字(占2个长度)
3. 然后StringBuilder append()

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        return says("1",n-1);
    }
    public String says(String s,int n){
        if(n==0) return s;
        s+="#";
        StringBuilder res=new StringBuilder();
        int count=0;
        for(int i=0;i<s.length()-1;i++){
              char a=s.charAt(i);
              char b=s.charAt(i+1);
              if(a!=b){
                res.append(i+1-count);
                res.append(a);
                count=i+1;
            }
        }
        return says(res.toString(),--n);
    }
}
```