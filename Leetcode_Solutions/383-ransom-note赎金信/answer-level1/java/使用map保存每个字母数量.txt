//题目关键是magazine中的每个字母只能用一个，所以这里用map维护magazine中每个字母的数量
```
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if (null == magazine || null == ransomNote){
            return false;
        }
        Map map = new HashMap();
        for(int i = 0; i < magazine.length(); i++){
            if(map.containsKey(magazine.charAt(i))){
                map.put(magazine.charAt(i),(Integer)map.get(magazine.charAt(i)) + 1);
            }else{
                map.put(magazine.charAt(i),1);
            }
        }
        
        for(int i = 0; i < ransomNote.length(); i++){
            if(!map.containsKey(ransomNote.charAt(i))){
                return false;
            }
            
            if((Integer)map.get(ransomNote.charAt(i)) <= 0){
                return false;
            }
            map.put(ransomNote.charAt(i), (Integer)map.get(ransomNote.charAt(i)) - 1);
        }
        return true;
    }
}
```
