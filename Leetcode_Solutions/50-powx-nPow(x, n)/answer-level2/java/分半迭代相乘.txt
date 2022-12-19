执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.21%
的用户
内存消耗 :
33.3 MB
, 在所有 Java 提交中击败了
76.41%
的用户
```
class Solution {
    public double myPow(double x, int n) {
        if(n==0)return 1;
        if(x==1)return 1;
        double res=1d;
        boolean neg = false;
        if(n<0)neg=true;
        if(n==Integer.MIN_VALUE){
            res=x; 
            n=Integer.MAX_VALUE;
            neg=true;
        }
        int nn=Math.abs(n);
        res = res*get(x,nn);
        if(!neg)return res;
        if(neg)return 1d/res;
        return res;
    }
    private double get(double x, int nn){
        double res=1;
        if(nn==1){
            return x;
        }else{
            double sub = get(x,nn/2);
            if(nn%2==1){
              res=x*sub*sub;
            }else{
               res=sub*sub;
            }
        }
        //System.out.println(nn+"_"+res);
        return res;
    }
}
```
