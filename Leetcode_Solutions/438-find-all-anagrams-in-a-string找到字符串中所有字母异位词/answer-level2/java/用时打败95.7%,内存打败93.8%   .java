```
public List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList<>();
        int[] dictionary = new int[26];
        int len1 = s.length();
        int len2 = p.length();
        if(len1<len2){
            return list;
        }
        //先生成p字符串的字符字典
        for(char chp:p.toCharArray()){
            dictionary[chp-'a']++;
        }
        //再生成s子串的第一个子串的字典
        char[] chars = s.toCharArray();
        int[] res = new int[26];
        for(int i=0;i<len2;i++){
            res[chars[i]-'a']++;
        }
        if(isaqu(dictionary,res)){
            list.add(0);
        }
        //更新s子串的字典
        for(int j=1;j<=len1-len2;j++){
            res[chars[j-1]-'a']--;
            res[chars[j+len2-1]-'a']++;
            if(isequ(dictionary,res)){
                list.add(j);
            }
        }
        return list;
    }
//比较两个字典
private boolean isequ(int[] dictionary,int[] res){
    for(int i=0;i<dictionary.length;i++){
        if(dictionary[i]!=res[i]){
            return false;
        }
    }
     return true;
}
```
