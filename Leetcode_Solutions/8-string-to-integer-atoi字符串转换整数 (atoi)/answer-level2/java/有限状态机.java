

模仿官方题解思路，用 java 抄了一遍
```
class Solution {
    // status
    int START = 0 , SIGNED = 1, IN_NUM = 2, END = 3;
    int[][] status = new int[][]{{START,SIGNED,IN_NUM,END},{END,END,IN_NUM,END},
            {END,END,IN_NUM,END},{END,END,END,END}};

    int MIN_VALUE_10 = Integer.MIN_VALUE / 10;
    int MAX_VALUE_10 = Integer.MAX_VALUE / 10;

    public int myAtoi(String str) {
        // 起始状态
        int result = 0, curStatus = START;
        // 正负数标识 0 -> + , 1 -> -
        int signed = 0;

        for(char a : str.toCharArray()){
            int tempStatus = status[curStatus][getCol(a)];
            if (tempStatus == END){
                return signed == 0 ? result : -result;
            }else if (tempStatus == SIGNED){
                if(a == '+') signed = 0;
                if(a == '-') signed = 1;
            }else if (tempStatus == START){
                continue;
            }else{
                // 需要处理边值
                if(signed == 0 && (result > MAX_VALUE_10 || 
                    (result == MAX_VALUE_10 && (int)a > 55 ))){
                    return Integer.MAX_VALUE;
                }
                if(signed == 1 && (-result < MIN_VALUE_10 || 
                    (-result == MIN_VALUE_10 && (int)a > 56))){
                    return Integer.MIN_VALUE;
                }
                result = result * 10 + (int)a - 48;
            }
            curStatus = tempStatus;
        }
        return signed == 0 ? result : -result;
    }
    
    public int getCol(char source){
        if(source == ' ')
            return 0;
        if(source == '+' || source =='-')
            return 1;
        if((int)source >= 48 && (int)source <= 57  )
            return 2;
        return 3;
    }
}
```
