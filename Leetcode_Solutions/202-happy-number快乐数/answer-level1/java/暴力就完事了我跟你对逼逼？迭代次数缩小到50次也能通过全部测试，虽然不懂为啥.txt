### 解题思路
执行用时 :
7 ms
, 在所有 java 提交中击败了
8.12%
的用户
内存消耗 :
35.8 MB
, 在所有 java 提交中击败了
9.86%
的用户
### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        boolean res=false;
        String str_n=String.valueOf(n);
        char [] chars_n=str_n.toCharArray();
        int time=0;
        while(time<50) {
            int sum=0;
            for (int i = 0; i < chars_n.length; i++) {
                int each_wei=Integer.parseInt(String.valueOf(chars_n[i]));
                sum+=each_wei*each_wei;
            }
            if(sum==1){
                return true;
            }
             str_n=String.valueOf(sum);
             chars_n=str_n.toCharArray();
            time++;
        }
        return res;
    }
}
```