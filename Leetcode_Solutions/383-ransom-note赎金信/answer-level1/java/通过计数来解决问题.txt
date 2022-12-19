```
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] num=new int[26]; //定义一个int型数组，来统计每个字符出现的次数
        for(int i=0;i<magazine.length();i++){
            num[magazine.charAt(i)-'a']++; 
        }
        for(int i=0;i<ransomNote.length();i++){
            if(num[ransomNote.charAt(i)-'a']==0){ //如果该字母出现次数为0，则返回false
                return false;
            }
            num[ransomNote.charAt(i)-'a']--; //否则将该字母可用次数减一
        }
        return true; 
    }
}
```

