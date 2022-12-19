没啥好说的，最原始的方法，速度还行，2ms

```
class Solution {
    public int myAtoi(String str) {
        int len=str.length();
        if(len==0) return 0;
        long sum=0;
        int star=0,end;
        char t=str.charAt(star);
        while(t==' '){
            star++;
            if(star<len) t=str.charAt(star);
            else return 0;
        }
        if(t=='-'||t=='+'||(t>='0'&&t<='9')){
            int tag;
            if(t=='-') tag=-2;
            else if(t=='+') tag=-1;
            else tag=t-'0';
            
            end=star+1;
            if(end<len) t=str.charAt(end);
            else return tag>0? tag:0;
            
            while(t>='0'&&t<='9'){
                end++;
                if(end<len) t=str.charAt(end);
                else break;
            }
            
            end--;

            int pow=0;
            for(int i=end;i>star;i--){
                sum+=(str.charAt(i)-'0')*Math.pow(10,pow);
                pow++;
            }

            if(tag==-2) {
                if(sum>Integer.MAX_VALUE) return Integer.MIN_VALUE;
                return (int)-sum;
            }
            else if(tag==-1) {
                if(sum>Integer.MAX_VALUE) return Integer.MAX_VALUE;
                return (int)sum;
            }
            else{
                sum+=tag*Math.pow(10,pow);
                if(sum>Integer.MAX_VALUE) return Integer.MAX_VALUE;
                return (int)sum;
            }
        }
        else return 0;
    }
} 
```
