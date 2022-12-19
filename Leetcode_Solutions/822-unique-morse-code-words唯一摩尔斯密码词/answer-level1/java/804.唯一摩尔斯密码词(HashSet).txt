```
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String morse[]=new String[]{
			".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
		};

		HashSet<String>set=new HashSet<>();
		for(String str:words){
			StringBuilder sb=new StringBuilder();
			for(char c:str.toCharArray()){
				sb.append(morse[c-'a']);
			}
			set.add(sb.toString());	
		}
		return set.size();
    }
}
```