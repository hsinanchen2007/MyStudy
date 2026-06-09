执行结果：
通过
显示详情
执行用时 :
12 ms
, 在所有 Java 提交中击败了
13.32%
的用户
内存消耗 :
37.7 MB
, 在所有 Java 提交中击败了
21.25%
的用户
```
class Solution {
    public String addBinary(String a, String b) {
        int la = a.length();
        int lb = b.length();
        if(la==0)return b;
        if(lb==0)return a;
        int ia=la-1;
        int ib=lb-1;
        int last = 0;
        int lc = Math.max(la,lb);
        char[] res = new char[lc];
        int ic=lc-1;
        while(ia>=0&&ib>=0){
            char ca = '0';
            if(ia>=0){
                ca = a.charAt(ia);
            }
            char cb = '0';
            if(ib>=0){
                cb = b.charAt(ib);
            }
            int x=Integer.valueOf(""+cb)+Integer.valueOf(""+ca)+last;
            last=x/2;
            res[ic]=Character.forDigit(x%2,2);
            ic--;
            ia--;
            ib--;
        }
        while(ia>=0){
            char ca = '0';
            if(ia>=0){
                ca = a.charAt(ia);
            }
            
            int x=Integer.valueOf(""+ca)+last;
            last=x/2;
             res[ic]=Character.forDigit(x%2,2);
            ia--;
            ic--;
            
        }
        while(ib>=0){
           
            char cb = '0';
            if(ib>=0){
                cb = b.charAt(ib);
            }
            int x=Integer.valueOf(""+cb)+last;
            last=x/2;
            res[ic]=Character.forDigit(x%2,2);
            ic--;
            ib--;
        }
        
        return (last==1)?1+new String(res):new String(res);
    }
}
```
