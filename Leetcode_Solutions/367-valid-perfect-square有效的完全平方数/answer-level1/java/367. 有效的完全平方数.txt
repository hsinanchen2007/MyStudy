/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/3
 *
 * 解题思路: 牛顿迭代法
 */
![CD3748A47C35F5B3DFAE630318C8FF67.png](https://pic.leetcode-cn.com/759c6f0a96371eb2f6217d95aa14021d05e42567738492bf5a7810366e10f89f-CD3748A47C35F5B3DFAE630318C8FF67.png)

```
  public boolean isPerfectSquare(int num) {
        if(num <= 0){
            return false;
        }

        double x = 1.0;
        while(Math.abs(x*x - num)>1e-9){
            x = (x + num/x)/2;
        }
        int x_i = (int)x;
        if(x_i * x_i != num){
            return false;
        }
        return true;
    }
```