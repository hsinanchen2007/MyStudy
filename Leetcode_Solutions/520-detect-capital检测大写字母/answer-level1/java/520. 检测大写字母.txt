/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/22
 *
 * 解题思路: 先确定前两个单词的大小写 即可确定之后字母是小写 还是 大写
 *
 */

```
public boolean detectCapitalUse(String word) {
    char[] word_arr = word.toCharArray();

    if(word_arr.length == 0 || word_arr.length == 1){
        return true;
    }

    boolean first_upper ;
    if(word_arr[0] >= 'a' && word_arr[0] <= 'z'){
        first_upper = false;
    }else{
        first_upper = true;
    }
    boolean second_upper;
    if(word_arr[1] >= 'a' && word_arr[1] <= 'z'){
        second_upper = false;
    }else{
        second_upper = true;
    }
    for(int i = 1;i < word_arr.length;i++){
        if(first_upper == false && word_arr[i] >= 'A' && word_arr[i] <= 'Z'){ //首字母小写
            return false;
        }else if(first_upper == true && second_upper == true && word_arr[i] >= 'a' && word_arr[i] <= 'z'){
            return false;
        }else if(first_upper == true && second_upper == false && word_arr[i] >= 'A' && word_arr[i] <= 'Z'){
            return false;
        }
    }
    return true;
}
```