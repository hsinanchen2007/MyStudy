```java
//next数组
    public String longestPrefix(String s) {
        int n=s.length();
        int[] next=new int[n];
        next[0]=-1;
        for(int i=1; i<n; i++){
            int si=next[i-1];
            while(s.charAt(i)!=s.charAt(si+1)){
                if(si==-1){
                    si=-2;
                    break;
                }
                si=next[si];
            }
            next[i]=si+1;
        }
        return s.substring(0,next[n-1]+1);
    }
```
