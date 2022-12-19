
为啥我会超时？
```
class Solution {
    public String reverseVowels(String s) {
        char[] cs = s.toCharArray();
        
        int start = 0;
        int end = cs.length-1;
        while(start < end){
            char  temp = cs[start];
            if(isVowel(temp) && isVowel(cs[end])){
                 cs[start] = cs[end];
                 cs[end] = temp;
            }
            if(!isVowel(temp)){
                start++;
            }
            if(!isVowel(cs[end])){
                end--;
            }
        }
        return cs.toString();
    }

    //判断是否元音
    public boolean isVowel(char c){
        boolean is = false;
        switch(c){
            case 'a':
            case 'o':
            case 'e':
            case 'i':
            case 'u':
                is = true;
                break;
            default:
                is = false;
        }
        return is;
    }

}

```
