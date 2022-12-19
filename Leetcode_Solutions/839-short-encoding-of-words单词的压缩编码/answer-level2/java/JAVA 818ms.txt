### 解题思路
max()每次返回数组中最长的项，并把该项置空，循环匹配子串是否已存在，一定要先加#再匹配,abbba#和bbb匹配，abbba#和bbb#不匹配

### 代码

```java
class Solution {
    public static String[] w;
    public int minimumLengthEncoding(String[] words) {
        if(words.length<1){
            return 0;
        }
        w=words;
        String s="";
        for(int i=0;i<words.length;i++){
            String tmp = max();
            tmp+="#";
            if(s.indexOf(tmp)==-1){
                s+=tmp;
            }
        }
        return s.length();
    }

    public String max(){
        int t=0;
        for(int i=0;i<w.length;i++){
            if(w[t].length()<=w[i].length()){
                t=i;
            }
        }
        String a=w[t];
        w[t]="";
        return a;
    }
}
```