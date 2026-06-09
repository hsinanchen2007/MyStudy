### 解题思路
奇数直接遍历输出，偶数=奇数+奇数。

### 代码

```java
class Solution {
    public String generateTheString(int n) {
        StringBuilder sb = new StringBuilder();
        if(n % 2 == 0){
            for(int i = 0;i<n-1;i++){
                sb.append("a");
            }
            sb.append("b");
        }else{
            for(int i = 0;i<n;i++){
                sb.append("a");
            }
        }
        return sb.toString();
    }
}
```