class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        int length = s.length();
        char[] sarray = s.toCharArray();
        char[] tarray = t.toCharArray();
        Map map = new HashMap();
        
        for(int i=0; i<length; i++)
        {
            if(map.get(sarray[i]) != null){
                sarray[i] =(char) map.get(sarray[i]);
            }else{
                if(map.containsValue(tarray[i])){ //判断是否多键对应一个值
                    return false;
                }
                map.put(sarray[i],tarray[i]);      
                sarray[i] = tarray[i];
            }
            
            if(sarray[i] != tarray[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
}