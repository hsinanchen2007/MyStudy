### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

        public boolean oneEditAway(String first, String second) {

        if (first==null || second==null) return false;
        else if ((first.length()==1) && (second.length()<=1)) return true;
        else if (Math.abs(first.length()-second.length())>1)  return false;

        if (first.length()>second.length())

            return  deleteOneCharThenCompare(first,second);

        else if (first.length()==second.length())

            return  predicate(first,second);
        else
            return  deleteOneCharThenCompare(second,first);
    }

    private boolean deleteOneCharThenCompare(String more, String less){

        int pos = 0;
        int miss=0;
        StringBuilder sb = new StringBuilder(more);
        while (pos<less.length()){
            // 不相等直接去除不相等的字符串再比较
            if (sb.toString().charAt(pos)!=less.charAt(pos)){ 
                sb.replace(pos,pos+1,"");
                miss++;
                if (miss>1) return false;
                continue;
            }
            pos++;
        }
        return true;
    }
    private boolean predicate(String first, String second){
        int pos = 0;
        int miss=0;
        String[] f = first.split("");
        String[] s = second.split("");
        while (pos < first.length()) {
            if (!f[pos].equals(s[pos]))
                miss++;
            pos++;
        }
        return miss<=1;
    }
}
```