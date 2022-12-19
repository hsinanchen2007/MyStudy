```
public int uniqueMorseRepresentations(String[] words) {
        String[] strings={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    Set<String> set=new HashSet<String>();
    for (int i = 0; i < words.length; i++) {
        String string=words[i];
        StringBuffer buffer=new StringBuffer();
        for (int j = 0; j < string.length(); j++) {
            buffer.append(strings[string.charAt(j)-97]);
        }
        set.add(buffer.toString());
    }
    return set.size();
}
```
