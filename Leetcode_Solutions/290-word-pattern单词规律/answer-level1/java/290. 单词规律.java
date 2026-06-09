/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/2
 *
 * 解题思路: 使用hash 存储 pattern 与 str 已经匹配的映射关系，每次判断当前的pattern str 是否已经存在，存在且匹配继续 不存在不匹配加入 否则false
 */

```
public boolean wordPattern(String pattern, String str) {
    HashMap<Character,String> hashMap = new HashMap<>();

    char[] pattern_arr = pattern.toCharArray();

    String[] str_arr = str.split(" ");

    if(pattern_arr.length != str_arr.length){
        return false;
    }

    for(int i = 0; i < pattern.length();i++){
        if(!hashMap.containsKey(pattern_arr[i])){
            if(hashMap.containsValue(str_arr[i])){
                return false;
            }else{
                hashMap.put(pattern_arr[i],str_arr[i]);
            }
        }else{
            if(!hashMap.get(pattern_arr[i]).equals(str_arr[i])){
                return false;
            }
        }
    }
    return true;
}
```