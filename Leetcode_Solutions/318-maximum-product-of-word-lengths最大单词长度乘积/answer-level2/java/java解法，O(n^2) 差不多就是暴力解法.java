执行用时 :221 ms, 击败了20.55%的用户。
内存消耗 :101.9 MB, 击败了10.81%的用户。
```
class Solution {
    public int maxProduct(String[] words) {
        int max = 0;
        for(int i = 0; i< words.length-1; i++){
            Set<Character> set = new HashSet<>();
            for(char c : words[i].toCharArray()){
                set.add(c);
            }
            P:for(int j = i+1; j < words.length; j++){
                if(words[i].length()*words[j].length() <= max){
                    continue;
                }
                for(char c : words[j].toCharArray()){
                    if(set.contains(c)){
                        continue P;
                    }
                }
                max = words[i].length()*words[j].length();
            }
        }
        return max;
    }
}
```
