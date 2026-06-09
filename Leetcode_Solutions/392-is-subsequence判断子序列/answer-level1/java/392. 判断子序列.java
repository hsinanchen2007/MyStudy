/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/5
 *
 * 解题思路1: O(n)进行遍历s t 求解
 *
 * 解题思路2: 使用java indexof() 函数,效率貌似很高,函数内部应该做了结构优化,后面有时间研究一下
 *
 */

```

public boolean isSubsequence(String s, String t) {
    char[] s_arr = s.toCharArray();
    char[] t_arr = t.toCharArray();

    int i = 0 ,j =0;
    for( i = 0 , j = 0;i < t_arr.length && j < s_arr.length;i++){
        if(s_arr[j] == t_arr[i]){
            j++;
        }
    }
    if(j == s_arr.length){
        return true;
    }
    return false;
}

public boolean isSubsequence2(String s, String t) {
    char[] s_arr = s.toCharArray();

    int i = 0 ;
    int index = 0;
    for( i = 0 ;i < s_arr.length;i++){
        index = t.indexOf(s_arr[i],index);
        if(index == -1){
            return false;
        }
        //下一个位置开始
        index++;
    }
    return true;
}


```