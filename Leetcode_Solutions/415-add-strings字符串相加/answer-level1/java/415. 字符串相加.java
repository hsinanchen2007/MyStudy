/**
 * Project:
 * Author : zhaozhen
 * Email  : 2399144252@qq.com
 * Date   : 2019/9/9
 * 
 * 解题思路: 大整数相加
 * 
 */
```
  public String addStrings(String num1, String num2) {

        char[] num1_arr = num1.toCharArray();
        char[] num2_arr = num2.toCharArray();
        char[] num_arr_res = new char[Math.max(num1_arr.length,num2_arr.length) + 1];

        int pre = 0;
        int i , j , k;
        for(i = num1_arr.length - 1 , j = num2_arr.length -1, k = num_arr_res.length - 1; i >= 0 || j >= 0; i--,j--,k--){

            int temp = 0;
            if(i < 0){
                 temp = num2_arr[j] - '0' + pre;
            }else if( j < 0){
                 temp = num1_arr[i] - '0'  + pre;
            }else {
                 temp = num1_arr[i] - '0' + num2_arr[j] - '0' + pre;
            }
            if(temp > 9){
                num_arr_res[k] = (char)(temp - 10 + '0');
                pre = 1;
            }else{
                num_arr_res[k] = (char)(temp + '0');
                pre = 0;
            }
        }

        if(pre == 1){
            num_arr_res[0] = (char)(pre + '0');
            return String.valueOf(num_arr_res);
        }
        return String.valueOf(num_arr_res).substring(1,num_arr_res.length);

    }
```