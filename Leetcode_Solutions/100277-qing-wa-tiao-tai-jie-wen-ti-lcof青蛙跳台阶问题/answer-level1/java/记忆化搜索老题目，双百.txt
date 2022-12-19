此题与70,509,1137,上一题类似，只与输入数字有关
```
class Solution {
    public int numWays(int n) {
      int []a=new int[n+2];
      return numWays(0,n,a);
    }

    public int numWays(int i,int n,int []a){
      if(i>n){return 0;}
      if(i==n){return 1;}
      if(a[i]>0){return a[i];}
      a[i]=(numWays(i+1,n,a)+numWays(i+2,n,a))%1000000007;
      return a[i];
    }
}
```
![图片.png](https://pic.leetcode-cn.com/1d0736f36bcd50708edd4a57c04ecfbc644de3682eb76c928850c6632bed2372-%E5%9B%BE%E7%89%87.png)
