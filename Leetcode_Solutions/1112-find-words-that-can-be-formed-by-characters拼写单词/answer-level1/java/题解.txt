class Solution {
    public int countCharacters(String[] words, String chars) {
        int number = 0 ;
        for(String word:words){
            String charString = chars;
            for(int i = 0;i<word.length();i++){
                String str = word.charAt(i)+"";//单词中的每个字母
                if(charString.indexOf(str)==-1){//如果不存在
                    number=number-i;
                    charString = chars;//如果匹配不上的话需要还原字符串。不然就会被永久剔除咯
                    break;
                }else{
                    int index = charString.indexOf(str);//当前字母在字符串中的索引
                    charString = charString.substring(0,index)+charString.substring(index+1);
                    number++;
                }
            }
        }
        return number;
    }
}