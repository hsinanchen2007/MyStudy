执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
95.59%
的用户
内存消耗 :
34.1 MB
, 在所有 Java 提交中击败了
16.41%
的用户
```
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int c = 0;
        int zero=0;
        boolean neg = false;
        boolean zz = true;
        if(n<0)neg=true;
        if(neg){
            while(n!=0){
                int i = n%2;
                if(i==-1){
                    c++;
                    if(zz){
                        zz=false;
                    }
                }else{
                    if(zz){
                        zero++;
                    }
                }
                
                n=n/2;
            }
            //1+(31-c)+(-zero+1)
            c=33-c-zero;
        }else{
            while(n!=0){
                int i = n%2;
                if(i==1)c++;
                n=n/2;
            }
        }
        return c;
    }
}
```
