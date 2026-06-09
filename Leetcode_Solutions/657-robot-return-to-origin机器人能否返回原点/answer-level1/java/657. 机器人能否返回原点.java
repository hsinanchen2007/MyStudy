/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 *
 * 解题思路: x y 数字化 最终 x y 都为0的话就是回到原点
 *
 */
```
public boolean judgeCircle(String moves) {
    char[] moves_arr = moves.toCharArray();
    int x= 0;
    int y = 0;
    for(int i = 0;i < moves_arr.length;i++){
        switch (moves_arr[i]){
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
                break;
            default:
                x++;
                break;
        }
    }
    if(x == 0 && y == 0) return true;
    else return false;
}
```