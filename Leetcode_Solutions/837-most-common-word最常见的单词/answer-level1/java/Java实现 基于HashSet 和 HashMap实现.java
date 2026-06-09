
```
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> set = new HashSet<>();
        for(String bannedWord : banned)
            set.add(bannedWord.toLowerCase());//注意转为小写
        Map<String,Integer> map = new HashMap<>();
        
        int len = paragraph.length();
        int i = 0;
        //构造一个新的字符串，单词间用空格分隔 便于分割
        StringBuffer sb = new StringBuffer();
        while(i < len){
            if(!isZiMu(paragraph.charAt(i))){
                while(i < len && !isZiMu(paragraph.charAt(i)))
                    i++;
                if(i != len)
                    sb.append(' ');
            }else
                sb.append(paragraph.charAt(i++));
        }
        
        String[] words = sb.toString().split(" ");
        
        for(String word : words){
            //转为小写
            word = word.toLowerCase();
            if(!set.contains(word)){
                map.put(word,map.getOrDefault(word,0) + 1);
            }
        }
        
        String key = null;
        int max = 0;
        for(String k : map.keySet()){
            //System.out.println(k + " ");
            if(map.get(k) > max){
                max = map.get(k);
                key = k;
            }
        }
        return key;
    }
    
    //判断是否属于字母
    private boolean isZiMu(Character c){
        if(c >= 'A' && c <= 'Z')
            return true;
        if(c >= 'a' && c <= 'z')
            return true;
        return false;
    }
}
```
