/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/11
 * 
 * 解题思路: 话不多说 hash
 * 
 */
```
public int numJewelsInStones(String J, String S) {
    int sum = 0;
    char[] J_arr = J.toCharArray();
    char[] S_arr = S.toCharArray();
    char letters[] = new char['z' - 'A' + 1];

    for(int i = 0;i < J_arr.length;i++){
        letters[J_arr[i] - 'A']++;
    }
    
    for(int i = 0;i < S_arr.length;i++){
        if(letters[S_arr[i] - 'A'] > 0 ){
            sum++;
        }
    }
    return sum;
}
```