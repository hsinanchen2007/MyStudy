其他类似题目有509，1137,70
509与这道题差取余
1137和70与这道题差带入值

```
class Solution {
    public int fib(int n) {
      int []a=new int[n+1];    
      return fib(0,n-1,a);
    }
    public int fib(int i,int n,int []a){
      if(i==n){return 1;}
      if(i>n){return 0;}
      if(a[i]>0){return a[i];}
      a[i]=(fib(i+1,n,a)+fib(i+2,n,a))%1000000007;     
      return a[i];
    }
}
```
![图片.png](https://pic.leetcode-cn.com/b042c4037795df2f76f4e338a2af20899d7d4ade78cc50146762a5d45db78a42-%E5%9B%BE%E7%89%87.png)
