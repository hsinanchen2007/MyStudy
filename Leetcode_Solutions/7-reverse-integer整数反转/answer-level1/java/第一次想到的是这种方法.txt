### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        boolean flag = true;
        flag =  x<0?false:true;

        String a = String.valueOf(x);
        String b;
        b = (flag == false)?"-":"";

        for(int i = a.length() ; i > 0 ; i-- ){
            if(flag == false && i == 1){
                break;
            }
            b = b + a.substring(i-1,i);
        }
        return (int)Long.parseLong(b)==Long.parseLong(b)?(int)Long.parseLong(b):0;
    }
}
```