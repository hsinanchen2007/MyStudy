### 解题思路
利用非尾递归先执行最内层的特点将对称的数字带到外层进行比较。

### 代码

```java
class Solution {

    private int temp;

    public boolean isPalindrome(int x) {
        //边界判断
        if(x < 0) {
            return false;
        }
        
        //初始化
        temp = x;

        return recursive(x);
    }

    private boolean recursive(int num) {
        //边界判断
        if(num == 0) {
            return true;
        }
        
        //主逻辑
        if(!recursive(num/10)) return false;
        if(num%10 != temp%10) return false;
        temp = temp/10;

        return true;
    }
}
```