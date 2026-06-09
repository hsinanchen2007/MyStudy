### 解题思路
用StringBuffer的反转方法

### 代码

```java
class Solution {
    public int reverse(int x) {
        int res = 0;
        try {
            String number = String.valueOf(x);
            StringBuffer sb = new StringBuffer(number).reverse();
            if(sb.indexOf("-")>0){
                String result = "-"+ sb.toString().substring(0,sb.length()-1);
                res = Integer.valueOf(result);
            }else{
                String result = sb.toString();
                res = Integer.valueOf(result);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
        return res;
    }
}
```