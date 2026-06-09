很高兴能从ASCII值得灵感想出这种方法，还有利用了Set数组结构的不重复性：

```
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        int count = 0;
        Set<String> set = new HashSet<>();
        String [] sum = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",                             "...","-","..-","...-",".--","-..-","-.--","--.."};


        for(int i=0;i<words.length;i++){
             String s1="";
             String s = words[i];
            for(int j=0;j<s.length();j++){ 
                s1+=sum[s.charAt(j)-97];
            }
            if(set.add(s1)==true)
               count++;
        }
        return count;
       
    }
}
```
