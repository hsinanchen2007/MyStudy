### 解题思路
1.去除前后空格 2.判断起始字符为“+”或“-”还是数字  3.转换为数字（最重要的是临界值的判断，坑了好久）

### 代码

```java
class Solution {
    public int myAtoi(String str) {
   int result = 0;
        str = str.trim();
        boolean symbol = true;
        try {
            char symbolFlag = str.charAt(0);
            String strTemp = "";
            int firSubscript = 0;
            if(symbolFlag == 45){//第一个为正或者负号
                symbol = false;
                str = str.substring(1,str.length());
            }else if(symbolFlag == 43){
                symbol = true;
                str = str.substring(1,str.length());
            }
            char[] strArr = str.toCharArray();
            for(int index = 0; index < strArr.length; index++){
                if(strArr[index] >= 48 && strArr[index] <= 57){
                    if((index - strTemp.length()) > 0) break;
                    strTemp += strArr[index];
                }
            }
            int pop;
            for(int i = 0; i < strTemp.length(); i++ ){
                pop = Integer.parseInt(strTemp.substring(i,i+1));
                if(result > (Integer.MAX_VALUE - pop) /10){
                    return symbol ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                }
                result = result*10 + pop;
            }
        }catch (Exception e){
            System.out.println("截取异常");
        }
        return symbol ? result : -result;
    }
}
```