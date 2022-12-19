/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/10
 *
 * 解题思路: 切分 注意Java中的split 会出现 "a   b  c" 切分后出现 "" 的情况
 *
 */
```
public int countSegments(String s) {
    int res = 0;
    //注意java中的split函数在切分过程中会出现 ""
    String[] s_arr = s.split(" ");
    for(String s1 : s_arr){
        if(s1.length() != 0){
            res ++;
        }
    }

    return res;
}

```