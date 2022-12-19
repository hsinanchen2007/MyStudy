/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/15
 *
 * 解题思路: 怎么想 怎么做 统计当前字符个数
 *
 * 注意: 跳出循环陷阱
 *
 */
```
public int compress(char[] chars) {

    int index = 0;
    char current_char = chars[0];
    int count = 1;
    for(int i = 1;i < chars.length;i++){
        if(current_char == chars[i]){
            count++;
        }else{
            chars[index++] = current_char;
            if(count > 1){
                char[] temp = String.valueOf(count).toCharArray();
                for(int j = 0; j < temp.length;j++){
                    chars[index++] = temp[j];
                }
            }
            current_char = chars[i];
            count = 1;
        }
    }
    chars[index++] = current_char;
    if(count > 1){
        char[] temp = String.valueOf(count).toCharArray();
        for(int j = 0; j < temp.length;j++){
            chars[index++] = temp[j];
        }
    }
    return index;
}
```