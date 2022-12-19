```
class Solution {
    public int firstUniqChar(String s) {
        Map map = new LinkedHashMap();
        int index = -1;
        for(int i = 0; i < s.length(); i++){
            if(!map.containsKey(s.charAt(i))){
                map.put(s.charAt(i),1);
            }else{
                map.put(s.charAt(i),2);    
            }
        }
        
        for(int i = 0; i < s.length(); i++){  //第二次遍历
            if((Integer)map.get(s.charAt(i)) == 1){
                index = i;
                break;
            }
        }
        return index;
    }
}
```
