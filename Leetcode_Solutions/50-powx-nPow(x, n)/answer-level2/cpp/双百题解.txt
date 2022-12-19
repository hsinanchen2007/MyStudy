![微信截图_20200315215918.png](https://pic.leetcode-cn.com/ff41ef3d05ce6d5cb1d1ab03627b967d289122475d2b4ab51f326429cacaa978-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200315215918.png)
解题思路：
简单的回归思想。至于边界判断，尝试了一下没用long，发现也可以，就没改，这样内存占用也是最少了。
```
class Solution {
public:
    double fun(double x,int n){
        if(n<=1){
            return x;
        }
        if(n%2==1){
            return fun(x*x,n/2)*x;
        }else{
            return fun(x*x,n/2);
        }
        
    }
    double myPow(double x, int n) {

        if(n==0) return 1;
        if(x==1) return 1;
        if(x==-1){
            if(n%2==0){
                return 1;
            }else{
                return -1;
            }
        } 
        if(n>=INT_MAX||n<=INT_MIN) return 0;
        if(n<0){
            x=1/x;
            n=-n;
        }

        return fun(x,n);
    }
};
```

