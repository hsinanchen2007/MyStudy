/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/9
 *
 * 解题思路: 递归判断当前字符串是否满足规则
 *
 */
```
public boolean isOneBitCharacter(int[] bits) {
    if(bits[bits.length - 1] == 1){
        return false;
    }else {
        return isBitChar(bits,0,bits.length-2);
    }
}

//判断字符串是否满足规则
public boolean isBitChar(int[] bits , int start , int end){

    if(start > end + 1){
        return false;
    }

    if(start == end + 1){
        return true;
    }

    boolean res = false;
    if(bits[start] == 1){
        res = isBitChar(bits,start + 2 , end);
    }else if(bits[start] == 0){
        res = isBitChar(bits,start + 1 , end);
    }

    return res;
}
```