/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/28
 *
 * 解题思路: 存储当前已经映射的字母对,在进行下一个的时候首先判断两个串的当前的字母  是否已经存在映射  ,是的话跳过,否则  是否已经存在映射, 检测通过的加入hash
 *
 * 两个hash 或者 一个hash检测key 和 value 是否存在(数据量小一个hash会快一点)
 *
 */

```
public boolean isIsomorphic(String s, String t) {
        char[] s_arr = s.toCharArray();
        char[] t_arr = t.toCharArray();

        HashMap<Character , Character> hashMapst = new HashMap<Character, Character>();
        //HashMap<Character , Character> hashMapts = new HashMap<Character, Character>();

        for(int i = 0;i < s_arr.length;i++){
            if(hashMapst.containsKey(s_arr[i]) && hashMapst.get(s_arr[i]) == t_arr[i]){
                continue;
            }else {
                if(!hashMapst.containsKey(s_arr[i]) && !hashMapst.containsValue(t_arr[i])){
                    hashMapst.put(s_arr[i],t_arr[i]);
                }else {
                    return false;
                }
            }
        }
        return true;
    }
```