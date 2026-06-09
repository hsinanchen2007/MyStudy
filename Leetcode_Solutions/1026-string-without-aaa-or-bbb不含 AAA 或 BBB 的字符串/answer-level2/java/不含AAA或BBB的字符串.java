### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String strWithout3a3b(int A, int B) {
       StringBuilder sb = new StringBuilder();
        while(A>0&&B>0){
            if(A>B){
                sb.append("aab");
                A-=2;B--;
            }else if(A==B){
                sb.append("ab");
                A--;B--;
            }else{
                sb.append("bba");
                A--;B-=2;
            }
        }
        if(A>0){
            while(A>0){
            sb.append("a");
            A--;
            }
        }
        else if(B>0){
            while(B>0){
            sb.append("b");
            B--;
            }
        }
        return sb.toString();
    }
}
```