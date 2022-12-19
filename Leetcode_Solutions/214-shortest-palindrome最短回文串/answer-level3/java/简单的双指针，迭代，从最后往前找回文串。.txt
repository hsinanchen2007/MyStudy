执行结果：
通过
显示详情
执行用时 :
337 ms
, 在所有 Java 提交中击败了
23.78%
的用户
内存消耗 :
35.9 MB
, 在所有 Java 提交中击败了
97.06%
的用户
```
class Solution {
    public String shortestPalindrome(String s) {
        
        int a = 0;
        int e = s.length();
        if(e==0)return s;
        int x = 0;
        abc:
        for(int i=e-1; i>=0; i--){
            int v=i;
            a = 0;
            while(a<v){
                if(s.charAt(a)==s.charAt(v)){
                    a++;
                    v--;  
                    if(a>=v){
                        x=i;
                        break abc;
                    }  
                }else{
                    break;
                }
            }
        }
        return rev(s.substring(x+1,s.length()))+s;
        

    }
    private String rev(String a){
        StringBuffer sb = new StringBuffer();
        for(int i=a.length()-1; i>=0; i--){
            sb.append(a.charAt(i));
        }
 
       return sb.toString();
    }
}
```
略微改造，先一次比遍历取出所有与第一个字母相等的位置。
执行结果：
通过
显示详情
执行用时 :
396 ms
, 在所有 Java 提交中击败了
17.77%
的用户
内存消耗 :
36.2 MB
, 在所有 Java 提交中击败了
92.16%
的用户
```
class Solution {
    public String shortestPalindrome(String s) {
        int a = 0;
        int e = s.length();
        if(e==0)return s;
        int x = 0;
        List<Integer> pos = new ArrayList<>();
        char ss = s.charAt(0);
        for(int i=e-1; i>=0; i--){
            if(ss==s.charAt(i)){
                pos.add(i);
            }
        }

        abc:
        for(Integer i: pos){
            int v=i;
            a = 0;
            while(a<v){
                if(s.charAt(a)==s.charAt(v)){
                    a++;
                    v--;  
                    if(a>=v){
                        x=i;
                        break abc;
                    }  
                }else{
                    break;
                }
            }
        }
        return rev(s.substring(x+1,s.length()))+s;
        

    }
    private String rev(String a){
        StringBuffer sb = new StringBuffer();
        for(int i=a.length()-1; i>=0; i--){
            sb.append(a.charAt(i));
        }
        return sb.toString();
    }
}
```



