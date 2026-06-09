/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/4
 *
 * 解题思路: 不多说 创建长度为26的字符数组构建hash
 *
 */
```
 public int firstUniqChar(String s) {
    char[] s_arr = s.toCharArray();
    char[] letter = new char[26];

    for(int i = 0; i < s_arr.length;i++){
        letter[s_arr[i] - 'a']++;
    }

    for(int i = 0; i < s_arr.length;i++){
        if(letter[s_arr[i] - 'a'] == 1){
            return s_arr[i];
        }
    }

    return -1;
}
```