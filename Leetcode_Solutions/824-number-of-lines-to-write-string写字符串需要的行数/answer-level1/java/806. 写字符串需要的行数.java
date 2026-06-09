/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 * 
 * 解题思路: 常规思路
 * 
 */
```
public int[] numberOfLines(int[] widths, String S) {
    int sum = 0;
    int[] res = new int[2];
    char[] S_arr = S.toCharArray();

    for(int i = 0;i < S_arr.length;i++){
        sum += widths[S_arr[i] - 'a'];
        if(sum < 100){
            // nothing
        }else if(sum == 100){
            res[0]++;
            sum = 0;
        }else{
            sum = widths[S_arr[i] - 'a'];
            res[0]++;
        }
    }
    if(sum != 0){
        res[0]++;
        res[1] = sum;
    }else{
        res[1] = 100;
    }
    return res;
}
```