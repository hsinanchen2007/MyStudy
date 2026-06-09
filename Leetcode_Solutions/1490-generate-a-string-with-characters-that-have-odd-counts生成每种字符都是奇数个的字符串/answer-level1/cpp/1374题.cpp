### 解题思路
当n为偶数那么我们的结果由n-1个“a”和1个b构成
当n为奇数那么我们的结果由n个“a构成”

### 代码

```java
class Solution {
    public String generateTheString(int n) {
        String res = "";
        if((n&1)== 0)
        {
            for(int i =0;i < n - 1;i ++)
            {
                res = res + "a";
            }
            res += "b";
        }
        else{
            for(int i =0;i < n;i ++)
            {
                res = res + "a";
            }
        }
        return res;

    }
}
```