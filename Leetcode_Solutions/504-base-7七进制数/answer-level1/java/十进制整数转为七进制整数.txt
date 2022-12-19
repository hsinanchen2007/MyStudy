### 解题思路
1.十进制整数化为其他进制数时，一般都要考虑正负、为0。
2.若是整数，需要逆序。

### 代码

```java
class Solution {
    public String convertToBase7(int num) {
        if(num == 0) return ("0");
        StringBuilder sb = new StringBuilder();

        int flag = (num>0)?1:-1;
        num = Math.abs(num);
        while(num != 0){
            sb.append(""+ (num%7));
            num = num/7;
        }
        if(flag < 0){
            sb.append ("-");
        }
        return sb.reverse().toString();
    }
}
```