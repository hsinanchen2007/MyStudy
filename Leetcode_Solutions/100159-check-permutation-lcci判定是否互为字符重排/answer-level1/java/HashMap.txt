对于我这种菜鸡来说直接想到的就是hashmap，遍历两个字符串,如果最后所有的value都是0就返回true，否则返回false；
```
import java.util.HashMap;
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length()!=s2.length()) return false;
        int len=s1.length();
        char[] c1=s1.toCharArray();
        char[] c2=s2.toCharArray();
        HashMap<Character,Integer> map=new HashMap<Character, Integer>();
        for (int i=0;i<len;i++){
            char cc1=c1[i];
            char cc2=c2[i];
            if(map.containsKey(cc1)){
                int value=map.get(cc1);
                map.put(cc1,value+1);
            }else {
                map.put(cc1,1);
            }
            if(map.containsKey(cc2)){
                int value=map.get(cc2);
                map.put(cc2,value-1);
            }else {
                map.put(cc2,-1);
            }
        }
        for (int i:map.values()){
            if(i!=0) return false;
        }
        return true;
    }
}
```
