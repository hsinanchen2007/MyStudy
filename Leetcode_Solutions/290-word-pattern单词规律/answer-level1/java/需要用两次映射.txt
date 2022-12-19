**个人觉得需要用两次映射**
**示例 "abba" "dog dog dog dog" 返回false**
**说明一个单词只能由一种字符表示**
**所以反过来判断一次HashMap<String Character>时是否符合**
**有不懂或者错误都可以call我嘻嘻**
```
![1571038140.png](https://pic.leetcode-cn.com/dceb1a766eb741c8b87731d156cc58eea2e6707612d73b0f496a9756245c0d21-1571038140.png)
class Solution {
    public boolean wordPattern(String pattern, String str) {
        boolean result1 = wordPattern_1(pattern,str);
        boolean result2 = wordPattern_2(pattern,str);
        boolean result = result1 && result2;
        return result;
    }
    
    public static boolean wordPattern_1(String pattern, String str) {
        HashMap<Character,String> hm = new HashMap<>();
        int len_pat = pattern.length();
        String[] str_split = str.split(" ");
        int len_str = str_split.length;
        if(len_pat != len_str){
            return false;
        }
        for(int i=0;i<len_pat;i++){
            char target = pattern.charAt(i);
            if(hm.containsKey(target) != true){//hm中不包含该字母
                hm.put(target,str_split[i]);//添加
            }else{//包含该字母
                if(hm.get(target).equals(str_split[i])){
                }else{
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean wordPattern_2(String pattern, String str) {
        HashMap<String,Character> hm = new HashMap<>();
        int len_pat = pattern.length();
        String[] str_split = str.split(" ");
        int len_str = str_split.length;
        if(len_pat != len_str){
            return false;
        }
        for(int i=0;i<len_pat;i++){
            char target = pattern.charAt(i);
            if(hm.containsKey(str_split[i]) != true){//hm中不包含该字符串
                hm.put(str_split[i],target);
            }else{//包含该字符串
                if(hm.get(str_split[i]).equals(target)){
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}
```
