
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/23
 *
 * 解题思路: 当 a 大于1 且 连续的l大于2 就不奖励 用参数记录就行 每一步进行判断一次
 *
 */
```

public boolean checkRecord(String s) {
    char[] s_arr = s.toCharArray();

    int is_a = 0;
    int is_l = 0;
    int cur_is_l = 0;
    for(int i = 0;i < s_arr.length;){
        if(s_arr[i] == 'A'){
            is_a++;
            i++;
        }else if(s_arr[i] == 'L'){
            cur_is_l = 0;
            while(i < s_arr.length && s_arr[i] == 'L'){
                cur_is_l++;
                i++;
            }
            if(is_l < cur_is_l){
                is_l = cur_is_l;
            }
        }else {
            i++;
        }
        if((is_a > 1) || (is_l > 2)){
            return false;
        }
    }
    return true;
}
```