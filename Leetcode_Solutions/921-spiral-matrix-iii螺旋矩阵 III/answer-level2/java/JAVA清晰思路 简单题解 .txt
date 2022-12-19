模拟过程即可。
```
class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int[][] res = new int[R*C][2];
        int step_len = 1;//当前最大步长
        int step_time = 2;//步长更新时钟
        int step_limit = 2*Math.max(R,C)-1;//这个值应该怎么设置呢（极端情况）搜索范围初始为1，step_len更新两次，搜索范围扩大1格，保证扩大后的范围内全部搜索到，step_len需要再增加一次。极端情况下，初始位置在东南角，因此，最小最大步长为step_limit = 2*(Math.max(R,C)-1)+1
        int temp_R = r0;//当前遍历横坐标
        int temp_C = c0;//当前遍历纵坐标
        int tag = 0;//下一个要输入的结果坐标
        int direct = 0; //0123东南西北
        while (step_len <= step_limit) {
            int step_count = step_len;
            while (step_count > 0) {
                if (0 <= temp_R && temp_R < R && 0<= temp_C && temp_C < C) {
                    res[tag][0] = temp_R;
                    res[tag][1] = temp_C;
                    tag++;
                }
                switch(direct){
                    case 0 :
                        temp_C++;
                        break; 
                    case 1 :
                        temp_R++;
                        break; 
                    case 2 :
                        temp_C--;
                        break;
                    case 3 :
                        temp_R--;
                        break;
                }                
                step_count--;               
            }
            step_time--;
            direct++;
            direct = direct % 4;
            if (step_time == 0) {
                step_len++;
                step_time = 2;
            }
        }
        return res;
    }
}
```

