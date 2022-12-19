不要学我，冗长案例提示：
没啥

class Solution {
    public boolean isPalindrome(String s) {
        char[] sc = s.toCharArray();
        ArrayList<Character> list = new ArrayList<>();
        int count = 0;

        for(char c1 : sc){
            if(Character.isLetter(c1) || Character.isDigit(c1)){
                list.add(Character.toLowerCase(c1));
            }
        }


        for (int i = 0; i < list.size() / 2; i++) {
            if(list.get(i) == list.get(list.size() - 1 - i)){
                count ++;
            }
        }

        
        if(count == list.size()/2){
            return true;
        }

        return false;    
    }
}