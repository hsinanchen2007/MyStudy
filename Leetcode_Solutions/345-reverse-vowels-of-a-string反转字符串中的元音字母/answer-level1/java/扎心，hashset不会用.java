```
class Solution {
    public String reverseVowels(String s) {
        char[] ch = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        int i;
        // HashSet<String> hs = new HashSet<String>();
        // hs.add("a");
        // hs.add("e");hs.add("i");
        // hs.add("o");hs.add("u");hs.add("A");hs.add("E");hs.add("I");hs.add("O");hs.add("U");
        for(i = 0;i < s.length();i++){
            if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U'){
                sb.append(ch[i]);
                ch[i] = '#';
            }
        }
        char[] cc = sb.toString().toCharArray();
        int j = cc.length - 1;
        i = 0;
        while(j >= 0 || i < s.length()){
            if(ch[i] == '#'){
                ch[i] = cc[j];
                j--;
            }
            i++;
            if(j == -1 || i == s.length()) break;
        }
        String ss = String.valueOf(ch);
        return ss;
    }
}
```
