/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/3
 * 
 * 解题思路: 双指针 注意大小写
 */
```
public String reverseVowels(String s) {

    StringBuilder sb = new StringBuilder(s);
    //char[] s_arr = s.toCharArray();
    HashSet<Character> yy = new HashSet<>();
    yy.add('a');
    yy.add('e');
    yy.add('i');
    yy.add('o');
    yy.add('u');

    for(int i = 0,j = s.length() - 1; i < j;){
        char l = Character.toLowerCase(sb.charAt(i));
        char r = Character.toLowerCase(sb.charAt(j));

        if(yy.contains(l) && yy.contains(r)){
            char t = sb.charAt(j);
            sb.setCharAt(j,sb.charAt(i));
            sb.setCharAt(i,t);
            i++;
            j--;
        }else{
            if(!yy.contains(l)){
                i++;
            }
            if(!yy.contains(r)){
                j--;
            }
        }
    }
    return sb.toString();
}
```