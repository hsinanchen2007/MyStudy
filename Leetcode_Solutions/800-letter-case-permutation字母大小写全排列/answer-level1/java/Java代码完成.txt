### 解题思路
一开始没有理解输出条件，后来才发现是对回溯的考察，通过递归的方式就能解决这道题。

### 代码

```java
class Solution {
    List<String> out = new ArrayList<>();
    public List<String> letterCasePermutation(String S) {
         
        char array[]=S.toCharArray();
        digui(0,array,out);
        return out;
    }
   
 public static void digui(int i, char[]a,List<String> list) {
       if(i>=a.length)
           list.add(String.valueOf(a));
       else if(a[i]-'0'>=0&&a[i]-'9'<=0)
           digui(++i,a,list);
       else {
           digui(++i,a,list);
           int flag=i-1;
           if(a[flag]-'a'>=0&&a[flag]-'z'<=0){
               a[flag]-=32;
               digui(flag+1,a,list);
               a[flag]+=32;
           }else{
               a[flag]+=32;
               digui(flag+1,a,list);
               a[flag]-=32;
           }

       }

    }
    
}
```