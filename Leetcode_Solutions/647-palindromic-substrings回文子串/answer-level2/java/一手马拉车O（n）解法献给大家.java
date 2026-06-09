```java
class Solution {
    public int countSubstrings(String s) {
        if(s.length()==0) return 0;
        int mx=0,id=0,count=0;
        
        StringBuilder sb = new StringBuilder(s);
        for(int i=0;i<=sb.length()-1;i+=2){
            sb.insert(i,"#");
        }
        sb.append("#");
        String str = sb.toString();
        
        int [] p = new int [str.length()];
        
        for(int i=0;i<=str.length()-1;i++){
            
            p[i] = mx>i? Math.min(p[2*id-i],mx-i+1):1;
            
            while(p[i]+i<=str.length()-1 && i-p[i]>=0){
                if(str.charAt(p[i]+i) == str.charAt(i-p[i])) p[i]++;
                else break;
            }
            
            if(p[i]+i-1>mx){
                id=i;
                mx=p[i]+i-1; 
            }  
            
            count+= p[i]/2;
            
        }
        return count;
        
    }
}
```