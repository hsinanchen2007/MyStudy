### 解题思路
利用substring一行代码AC

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
   // if(s.length()<n){
   //  		return null;
   //  	}
          //  String right=s.substring(n);
           // String left=s.substring(0,n);
          //  String result=right+left;
            return s.substring(n)+s.substring(0,n);     
    }
}
```