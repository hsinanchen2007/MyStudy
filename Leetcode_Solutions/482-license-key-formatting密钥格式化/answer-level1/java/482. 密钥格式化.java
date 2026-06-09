/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/18
 *
 * 解题思路: 这个题目逆序解决 注意使用StringBuilder 来解决 ，String 字符串拼接很费时间 会超时
 *
 *    StringBuilder拼接，线程不安全，速度最快（10000条记录大概0毫秒）
 *    StringBuffer拼接，线程安全，速度略快（10000条记录大概16毫秒）
 *    String拼接，线程安全，速度最慢（10000条记录大概265毫秒）
 */

```
 public String licenseKeyFormatting(String S, int K) {

    char[] S_arr = S.toCharArray();
    StringBuilder sb = new StringBuilder();
    int j = 0;
    for(int i = S_arr.length - 1; i >= 0; i --){
        if(S_arr[i] == '-')continue;
        if(j % K == 0 && j != 0){
            sb.append('-');
//                res = "-" + res;
        }
        sb.append(S_arr[i]);j++;
//            res = S_arr[i] + res; j++;

    }

    return sb.reverse().toString().toUpperCase();
}
```