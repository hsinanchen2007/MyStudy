### 解题思路
借鉴官方题解的思路，用Java实现自动机，使用一个二维int数组来表示自动机表。


### 代码

```java
class Solution {
    // 第一维数组：0:started 1:singed 2:in_number 3:end
    // 第二维数组：各个状态下遇到' ','+/-','0-9','其他字符'的状态切换
    public int[][] statusTable = {
        {0,1,2,3},
        {3,3,2,3},
        {3,3,2,3}
    };
    public int status = 0; // 当前状态
    public int singed = 1; // 符号位
    public int ans = 0;

    public int getCol(char ch){ // 获取列数
        if(ch == ' '){
            return 0;
        } else if (ch == '+' || ch == '-'){
            return 1;
        } else if (ch >= '0' && ch<='9'){
            return 2;
        } else {
            return 3;
        }
    }

    public int myAtoi(String str){
        for(char ch : str.toCharArray()){
            int col = getCol(ch);
            status = statusTable[status][col];
            if(status == 3){
                break;
            } else if(status == 1){
                singed = ch=='-'?-1:1;
            } else if(status == 2){
                boolean isOverIntegerMaxValue = ans > Integer.MAX_VALUE/10 || (ans == Integer.MAX_VALUE/10 && ch-'0' > Integer.MAX_VALUE%10);
                boolean isOverIntegerMinValue = ans > Integer.MAX_VALUE/10 || (ans == Integer.MAX_VALUE/10 && ch-'0' > ((long)Integer.MAX_VALUE+1)%10);
                if(isOverIntegerMaxValue && singed == 1){
                    return Integer.MAX_VALUE;
                }
                if(isOverIntegerMinValue && singed == -1){
                    return Integer.MIN_VALUE;
                }
                ans = (ch-'0') + ans*10;
            }
        }
        return ans*singed;
    }
}
```