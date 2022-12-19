```
class Solution {
    public String findLongestWord(String s, List<String> d) {
        int i,j;
        String res="";
        for(String t:d){
            i=0;
            j=0;
            while(i<s.length()&&j<t.length()){
                if(s.charAt(i)==t.charAt(j)){
                    i++;
                    j++;
                }
                else
                    i++;
            }
            if(t.length()==j&&compare(t,res))
                res=t;
                
        }
        return res;
    }
    
    boolean compare(String s1,String s2){
                if(s1.length()==s2.length()) 
                    return s1.compareTo(s2)<0;
                return s1.length()>s2.length();
            }
}
```
