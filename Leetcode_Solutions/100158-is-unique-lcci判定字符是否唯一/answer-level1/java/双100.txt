class Solution {
    public boolean isUnique(String astr) {
        Set<Character> charSet = new HashSet<Character>();
        for(char item: astr.toCharArray()){
            if(!charSet.add(item)){
                return false;
            }
        }
        return true;
    }
}