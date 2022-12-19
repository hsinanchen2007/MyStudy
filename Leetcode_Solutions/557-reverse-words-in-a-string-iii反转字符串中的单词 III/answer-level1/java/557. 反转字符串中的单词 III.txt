/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/23
 *
 * 解题思路:类似于双指针 start 记录单词开始 遇见空格就反转该单词  注意:最后一个单词要额外判断
 *
 */
```
 public String reverseWords(String s) {
    char[] s_arr = s.toCharArray();
    int start = 0;
    int i;
    for( i = 0;i < s_arr.length;i++){
        if(s_arr[i] == ' '){
            reverse(s_arr,start,i-1);
            if(i+1 < s_arr.length){
                start = i+1;
            }else{
                start = i;
            }
        }
    }
    if(start != s_arr.length){
        reverse(s_arr,start,s_arr.length-1);
    }

    return String.valueOf(s_arr);

}

public void reverse(char[] arr , int from ,int end){
    for(int i = from,j=end;i < j;i++,j--){
        char t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
```