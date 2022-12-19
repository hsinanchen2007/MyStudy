/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/11
 *
 * 解题思路: 常规题目 hash数组 + hashSet
 *
 */
```
 public int uniqueMorseRepresentations(String[] words) {
    String [] letter = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    HashSet<String> hashSet = new HashSet<>();

    for(String s:words){
        char[] s_arr = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i < s_arr.length;i++){
            sb.append(letter[s_arr[i] - 'a']);
        }
        hashSet.add(sb.toString());
    }
    return hashSet.size();
}
```