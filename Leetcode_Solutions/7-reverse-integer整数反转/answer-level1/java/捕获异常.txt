### 解题思路
超出返回捕获异常
### 代码

```java
class Solution {
    public int reverse(int x) {
        boolean flag = x >= 0 ? true : false;
        x = Math.abs(x);
        String v = String.valueOf(x);
        StringBuilder res = new StringBuilder();
        if(!flag) res.append("-");
        for(int i = v.length()-1;i >= 0;i--){
            res.append(v.charAt(i));
        }
        try{
            return Integer.parseInt(res.toString());
        }catch(Exception e){
            return 0;
        }
    }
}
```