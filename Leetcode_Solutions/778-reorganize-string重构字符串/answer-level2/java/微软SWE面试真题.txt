前两天面微软的时候的面试题
当时紧张光想着cornercase了，答得不好
回过神发现很简单的题想复杂了
记录一下

首先，判断误解的情况：
    奇数个字符，某个字符出现次数==(len+1)/2是可以的，如aabbb是有解的 让b在奇数位，a在偶数位babab即可，只有这一种情况需要特殊对待。
    奇数个字符，任意字符出现次数<(len+1)/2时，不需要从大到小排序了，只要插空就好，如 cccbbba————>cbcbcab
    偶数个字符，只要出现次数都小于等于长度的一半，不需要排序,如aaabbc————>ababac
    上代码：
```
class Solution {
    public String reorganizeString(String S) {
        char[] chars = S.toCharArray();
        int len=S.length();
        char morethanhalf=' ';
        char[] counts=new char[26];
        for(char c:chars){
            counts[c-'a']++;
            
            if(counts[c-'a']==(len+1)/2){morethanhalf=c;}
            else if(counts[c-'a']>(len+1)/2)return "";
        }
        int i=0;
        if(morethanhalf!=' '){
            counts[morethanhalf-'a']=0;
            
            while(i<len){
                chars[i]=morethanhalf;
                i+=2;
            }
        }
            for(int j=0;j<26;j++){
                while(counts[j]!=0){
                    if(i<len){
                        chars[i]=(char)('a'+j);
                        i+=2;
                    }else{i=1;chars[i]=(char)('a'+j);i+=2;}
                    counts[j]--;
                }
            }
            
        
        return String.valueOf(chars);       
    }
}
```
