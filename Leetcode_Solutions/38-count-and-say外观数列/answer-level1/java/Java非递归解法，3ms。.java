### 解题思路
这题目确实有点绕，看了评论区一个解释才懂。
我这个写法3ms，思路比较简单，就是依次遍历，各位可以看看

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        String curr="11";
        for(int i=3;i<=n;i++){
            StringBuilder temp=new StringBuilder();
            int anchor=0;
            for(int j=0;j<curr.length();j++){
                if((j+1)==curr.length()||curr.charAt(j)!=curr.charAt(j+1)){
                    temp.append(j+1-anchor);
                    temp.append(curr.charAt(j));
                    anchor=j+1;
                }
            }
            curr=temp.toString();
        }
        return curr;
    }
}
```