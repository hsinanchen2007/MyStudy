执行用时 :2 ms, 在所有 Java 提交中击败了69.29%的用户
内存消耗 :34.2 MB, 在所有 Java 提交中击败了72.18%的用户

主要思想是，进行快速乘法运算，通过递归调用cal() ;
cal方法：计算过程中达到入参n的一半就不再计算，避免i超过n;返回此次计算的i
在主方法中将递归计算出的i加到calculatedNum，当calculatedNum等于n，则退出循环，代表初步计算完成
出参res作为全局变量，在递归函数不停增加

```
class Solution {
    
    double res=1.0;  //出参res作为全局变量，在递归函数不停增加
    
    public double myPow(double x, int n) {
        boolean flag=true;
        boolean plus=false;
        if(n<0){
            flag=false; //负数
            if(n==Integer.MIN_VALUE){
                n=Integer.MAX_VALUE;
                plus=true;
            }else{
                n=0-n;              
            }
        }
        
        int m=n;
        int calculatedNum=0;  //已经计算的幂
        while(calculatedNum<n){   //已经计算的幂达到n，则退出循环
            calculatedNum=calculatedNum+cal(x,m);
            m=n-calculatedNum;
        }
     
        if(plus){
            res=res*x;
        }
        if(flag){  //正数
            res=res;
        }else{
            res=1.0/res;
        }
        return res;
    }
    
    private int cal(double x,int n){
        int i=1;
        while(i<n/2){   //达到入参n的一半就不再计算，避免i超过n;返回此次计算的i
            x=x*x;
            i=i+i;
        }
        res=res*x;
        return i;
    } 
}
```
