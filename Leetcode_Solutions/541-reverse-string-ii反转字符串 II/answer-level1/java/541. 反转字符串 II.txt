

/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/23
 *
 * 解题思路: 搞清楚题目的逻辑 反转每2*k个子序列的前k个序列 如果最后的序列不足2k 则 k<=l<2K  依旧反转前k个 0<l<k 全部反转
 *
 *  反转k个 跳过k个 最后剩余的不够k个,全部反转
 *
 *  代码两种写法 第二种好理解
 *
 */
```
public String reverseStr(String s, int k) {
        char[] s_arr = s.toCharArray();

        for(int i = 0;i < s_arr.length;){
            if(i + 2*k <= s_arr.length){
                //反转i - i+k
                reverseArr(s_arr , i,i + k - 1);
            }else if(i + k <= s_arr.length){
                //反转 i - i+k
                reverseArr(s_arr , i,i + k - 1);
            }else{ // if(i + k < s_arr.length - 1)
                //反转 i - s_arr.length - 1
                reverseArr(s_arr , i,s_arr.length - 1);
            }
            i += 2*k;
        }
        return String.valueOf(s_arr);
    }

public String reverseStr2(String s, int k) {
    char[] s_arr = s.toCharArray();

    for(int i = 0;i < s_arr.length;){
        //反转k
        if(i + k >= s_arr.length){
            reverseArr(s_arr,i,s_arr.length - 1);
            break;
        }else{
            reverseArr(s_arr,i,i + k-1);
        }
        i += k;

        //跳过k
        if(i + k >= s_arr.length){
            break;
        }
        i += k;
    }
    return String.valueOf(s_arr);
}

public void reverseArr(char[] arr , int from , int end){
    for(int i = from , j = end; i < j;i++ , j--){
        char t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
```