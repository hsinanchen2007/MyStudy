```
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1==null||s2==null){
            return false;
        }

        if(s1.length()!=s2.length()){
            return false;
        }

        Map<Character,Integer> m1 = new HashMap<>();
        Map<Character,Integer> m2 = new HashMap<>();

        for(int i=0;i<s1.length();i++){
            char ch1 = s1.charAt(i);
            if(m1.containsKey(ch1)){
                m1.put(ch1, m1.get(ch1)+1);
            }else{
                m1.put(ch1, 1);
            }

            char ch2 = s2.charAt(i);
            if(m2.containsKey(ch2)){
                m2.put(ch2, m2.get(ch2)+1);
            }else{
                m2.put(ch2, 1);
            }
        }

        for(char key:m1.keySet()){
            if(!m2.containsKey(key)){
                return false;
            }

            if(m1.get(key)!=m2.get(key)){
                return false;
            }
        }

        return true;
    }
}
```