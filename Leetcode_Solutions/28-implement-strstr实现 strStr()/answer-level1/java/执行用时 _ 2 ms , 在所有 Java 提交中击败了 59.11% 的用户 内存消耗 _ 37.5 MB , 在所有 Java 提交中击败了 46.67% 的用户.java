```
class Solution {
    public int strStr(String haystack, String needle) {
        int mystr=haystack.length();
        int mystr1 = needle.length();
        if(mystr1==0){
            return 0;
        }
        else if(mystr<mystr1){
            return -1;
        }else{
            int x=0;
            for(int i=0;i<mystr;i++){
                if(haystack.charAt(i)==needle.charAt(x)){//字符匹配相等
                    x++;
                    if(mystr1==x){
                        return i-mystr1+1;
                    }
                }
                else {//字符匹配不等
                    if(mystr-i+x-1<mystr1){//先判断剩下的字符串长度够不够
                        return -1;
                    }
                    else{//回溯字符
                        i=i-x;
                        x = 0;
                    }
                }

            }
            return -1;
        }
    }
}
```
还有就是可以直接截取字符串，那样速度更快。上面的方法是直接字符与字符比较的。