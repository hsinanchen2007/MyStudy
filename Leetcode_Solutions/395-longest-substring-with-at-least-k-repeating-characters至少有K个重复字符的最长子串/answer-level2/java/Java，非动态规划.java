最死板的做法，没有用到左右子串查找的方法。
而是先找到出现次数大于K组成最大的长度串，
然后再判断在子串中是否满足出现次数大于K的长度，
不停的往下找，直到该子串中出现的所有字符都是满足要求大于K次。

```
class Solution {
    public int longestSubstring(String s, int k) {
        if(k < 2) return s.length();
        return sub(s, k);
    }
    boolean flag;

    public int sub(String s, int k){
        if(s.length() < k)
            return 0;
        char[] chars = s.toCharArray();
        Map<Character, Integer> map = getMap(chars);
        int temp = 0;
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.length(); ){
            if(map.get(chars[i]) >= k){
                int j =  i;
                for(; j < s.length(); j ++ ){
                    if(map.get(chars[j]) < k)
                        break;
                }
                if(j - i >= k && j - i > temp){
                    temp = j - i;
                    start = i;
                    end = j;
                }
                i = j;
            }
            else {
                i ++;
            }
        }
        if (temp == s.length() || temp == 0)
            return temp;

        int result = sub(s.substring(start, end), k);
        if (flag || result == temp) {
            flag = true;
            return result;
        }
        else
            return 0;
    }
    
    public Map getMap(char[] chars){
        Map<Character, Integer> map = new HashMap();
        for(int i = 0; i < chars.length; i ++){
            Integer integer = map.get(chars[i]);
            if (integer != null)
                map.put(chars[i], integer + 1);
            else
                map.put(chars[i], 1);
        }
        return map;
    }
}
```