/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 *
 * 解题思路:通过空格切分成单词然后的进行判断处理
 *
 */
```
public String toGoatLatin(String S) {
    String[] s_arr = S.split(" ");

    char first_c;
    String addA = "a";
    StringBuilder sb = new StringBuilder();
    for(int i = 0;i < s_arr.length;i++){
        first_c = s_arr[i].charAt(0);
        //元音
        if(first_c == 'a' || first_c == 'e' || first_c == 'i' || first_c == 'o' || first_c == 'u'|| first_c == 'A' || first_c == 'E' || first_c == 'I' || first_c == 'O' || first_c == 'U'){
            sb.append(s_arr[i] + "ma" + addA);
        }else{ // 辅音
            sb.append(s_arr[i].substring(1) + first_c + "ma" + addA);
        }
        //加上空格
        if(i != s_arr.length - 1){
            sb.append(" ");
        }
        //索引a
        addA += "a";
    }

    return sb.toString();
}
```