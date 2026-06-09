```
class Solution {
    public String[] findWords(String[] words) {
        if(words==null||words.length==0) return new String[0];
        //用长度为26的数组标识每个字母所在的行号
        int[] map = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        List<String> list = new ArrayList<String>();
        for(String word:words){
            String tempWord = word.toUpperCase();
            int temp = map[tempWord.charAt(0)-65];
            boolean flag = true;
            //通过与首字母比较行号确定是否在同一行
            for(int i=1;i<tempWord.length();i++){
                if(temp != map[tempWord.charAt(i)-65]){
                    flag = false;
                    break;
                }
            }
            if(flag) list.add(word);
        }
        return list.toArray(new String[list.size()]);
    }
}
```
