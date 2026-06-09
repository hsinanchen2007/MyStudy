### 解题思路
先把num转成string，定义一个flag，把string转入StringBuilder，把6转成9.

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        StringBuilder sb = new StringBuilder();
        String str = String.valueOf(num);
        boolean flag = true;
        for(int i = 0;i<str.length();i++){
            sb.append(str.charAt(i));
            if(str.charAt(i) == '6'){
                if(flag){
                    sb.replace(i,i+1,"9");
                    flag = false;
                }
            }
        }
        return Integer.valueOf(sb.toString());
    }
}
```