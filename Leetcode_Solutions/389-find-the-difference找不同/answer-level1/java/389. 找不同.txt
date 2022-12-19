/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/5
 *
 * 解题思路1: 自定义hash字母表
 * 
 * 解题思路2: ASCII 码思维 ASCII对应字母的整数值 求和取差值即为添加的字母的ASCII
 *
 */
```
public char findTheDifference(String s, String t) {
    char[] s_arr = s.toCharArray();
    char[] t_arr = t.toCharArray();
    char[] letter = new char[26];

    for(int i = 0;i < s_arr.length;i++){
        letter[s_arr[i] - 'a']++;
    }

    for(int i = 0; i < t_arr.length;i++){
        if(letter[t_arr[i] - 'a'] == 0){
            return letter[i];
        }else {
            letter[t_arr[i] - 'a']--;
        }
    }
    return ' ';
}

public char findTheDifference2(String s, String t) {
    char[] s_arr = s.toCharArray();
    char[] t_arr = t.toCharArray();

    int sum = 0;

    for(int i = 0; i < t_arr.length;i++){
        sum += t_arr[i];
    }

    for(int i = 0;i < s_arr.length;i++){
        sum -= s_arr[i];
    }
    return (char)sum;
}
```