### 解题思路
因吹斯听...
![微信截图_20200323195352.png](https://pic.leetcode-cn.com/c1a0e47cba78f5139aa6b91824286715d35ca67167fda61da36923891ed89599-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200323195352.png)

递归

### 代码

```java
class Solution {
    public boolean isUgly(int num) {
        if(num<=0){
            return false;
        }else if(num >0 && num <7){
            return true;
        }else{
            return (num%2==0 && isUgly(num/2)) || (num%3==0&&isUgly(num/3)) || (num%5==0 &&isUgly(num/5));
        }
    }
}
```