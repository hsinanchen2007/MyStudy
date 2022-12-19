```
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] m = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Set<String> s = new HashSet<>();
        for(String c : words) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < c.length(); ++ i) {
                sb.append(m[c.charAt(i) - 'a']);
            } 
            s.add(sb.toString());
        }
        return s.size();
    }
}
```
