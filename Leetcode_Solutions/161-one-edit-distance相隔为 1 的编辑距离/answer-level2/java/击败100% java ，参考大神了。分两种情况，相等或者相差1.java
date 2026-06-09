class Solution {
    public boolean isOneEditDistance(String s, String t) {
        int n1 =s.length();
        int n2= t.length();
        if(Math.abs(n1-n2)>1){
            return false;
        }
        if(n1==1 && n2==0){
            return true ;
        }
        if(n1==0 && n2==1){
            return true ;
        }
        if(n2>n1){
            int tmp ;
            String str="";
            tmp=n1;
            n1=n2;
            n2=tmp;
            str=s;
            s=t;
            t=str;   
        }
        
        if(n1>n2){
            int c1=0,c2=0,count=0;
            while(c1<n1 && c2<n2){
                if(s.charAt(c1)==t.charAt(c2)){
                    c1++;
                    c2++; count++;
                }
                else if(s.charAt(c1)!=t.charAt(c2)){
                   
                    c1++;
                }
            }
            if(n1-count!=1){
                return false;
            }
        }


        if(n1==n2){
            int c1=0,c2=0,count=0;
            while(c1<n1 && c2<n2){
                if(s.charAt(c1)==t.charAt(c2)){
                    c1++;
                    c2++;count++;
                }
                else if(s.charAt(c1)!=t.charAt(c2)){
                    
                    c1++;
                    c2++;
                }
            }
            if(n1-count!=1)
            return false;
        }
        return true ;
    }
}