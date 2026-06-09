/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/10
 * 
 * 解题思路: 直接暴力完事
 * 
 */
```
public char nextGreatestLetter(char[] letters, char target) {
    int i = 0;
    for( i = 0;i < letters.length;i++){
        if(letters[i] == target){
            for(;i < letters.length;i++){
                if(letters[i] != target){
                    return letters[i];
                }
            }
            break;
        }else if(letters[i] > target){
            return letters[i];
        }
    }
    return letters[0];
}
```