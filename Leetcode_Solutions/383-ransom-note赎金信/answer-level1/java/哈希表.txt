哈希表存储ransom的字母每一次在magazine中出现的位置，出现重复元素则更新位置，直到遍历结束；
若后续在magazine中找不到元素位置则返回false;
```
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        char[] str_ran = ransomNote.toCharArray();
        
        //map存储ransomNote重复的字母及其每一次在magazine的位置;
        Map<Character,Integer> map = new HashMap<>();

        for(int i=0;i<str_ran.length;i++){
            int idx = 0;
            if(map.containsKey(str_ran[i])){
                idx = map.get(str_ran[i]);
            }
            
            //返回指定索引idx位置之后第一次出现该字符的索引号
            int newidx = magazine.indexOf(str_ran[i],idx);
            if(newidx==-1) return false;
            map.put(str_ran[i],newidx+1);
        }
        return true;
    }
}
```
