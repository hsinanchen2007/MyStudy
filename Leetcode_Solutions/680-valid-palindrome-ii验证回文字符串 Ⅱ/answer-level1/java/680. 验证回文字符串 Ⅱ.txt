/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 * 
 * 解题思路: 双指针 从数组的开头和末尾开始扫描 出现不一样字符进行模拟删除 
 *  删除i isHuiWen(s_arr,i+1,j)
 *  删除j isHuiWen(s_arr , i,j-1)
 *  然后判断剩余的是否为回文串 两种情况存在一种是回文串 则该字符串删除一个字符可以构成回文串
 * 
 */
```
public boolean validPalindrome(String s) {
    char[] letter = new char[26];

    char[] s_arr = s.toCharArray();

    for(int i = 0 , j = s_arr.length - 1;i < j;i++,j--){
        if(s_arr[i] != s_arr[j]){
            //两种删除方式
            return isHuiWen(s_arr , i,j-1) || isHuiWen(s_arr,i+1,j);
            
        }
    }
    return true;
}

public boolean isHuiWen(char[] s , int l , int r){
    for(int i = l , j = r ;i < j;i++,j--){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}
```