class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] password={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Set<String> hash=new HashSet<>();
        for(String str:words){
            StringBuilder s=new StringBuilder();//不能在外面创建该对象，否则每次执行完以后s的值不能重置
            for(char ch1:str.toCharArray()){
                s.append(password[ch1-'a']);
            }
            hash.add(s.toString());
        }
        return hash.size();
    }
}
利用hashset去重的特性来计算个数