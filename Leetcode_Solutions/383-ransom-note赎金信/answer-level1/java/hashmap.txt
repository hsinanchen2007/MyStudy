改了好久，虽然很慢但好歹做出来了
```
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character,Integer> hm = new HashMap<Character,Integer>();
        HashMap<Character,Integer> hmm = new HashMap<Character,Integer>();
        int i,coun = 0;
        for(i = 0;i < ransomNote.length();i++){
            if(hm.containsKey(ransomNote.charAt(i)))
                hm.put(ransomNote.charAt(i),hm.getOrDefault(ransomNote.charAt(i),0) + 1);
            else
                hm.put(ransomNote.charAt(i),0);
        }
        for(i = 0;i < magazine.length();i++){
            if(hmm.containsKey(magazine.charAt(i)))
                hmm.put(magazine.charAt(i),hmm.getOrDefault(magazine.charAt(i),0) + 1);
            else
                hmm.put(magazine.charAt(i),0);
        }
        for(i = 0;i < ransomNote.length();i++){
            int a = hm.get(ransomNote.charAt(i));
            if(!(hmm.containsKey(ransomNote.charAt(i))) )
                return false;
            if(hmm.get(ransomNote.charAt(i)) < a)
                return false;
        }
        return true;
    }
}
```
