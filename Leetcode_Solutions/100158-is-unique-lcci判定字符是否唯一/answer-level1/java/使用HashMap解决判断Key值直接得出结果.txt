class Solution {
    public boolean isUnique(String astr) {
     HashMap<Character,Integer> map=new HashMap();
        for(int i=0 ; i<astr.length();i++){
            if(!map.containsKey(astr.charAt(i))){
                map.put(astr.charAt(i),i);
            }else{
                return false;
            }
        }
        return true;
    }
}