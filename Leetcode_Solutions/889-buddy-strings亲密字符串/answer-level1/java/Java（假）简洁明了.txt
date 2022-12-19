```
class Solution {
    public boolean buddyStrings(String A, String B) {
        if(A.length()!=B.length()){return false;}
        if(A.equals(B)){
            for(int i=0;i<A.length()-1;i++){
                for(int j=i+1;j<A.length()-i;j++){
                    if(A.charAt(i)==A.charAt(j)){
                        return true;
                    }
                }
            }
            return false;
        }
        int temp1=0;
        int temp2=0;
        int count = 0;
        for(int i=0;i<A.length();i++){
            if(count>2){return false;}
            if(A.charAt(i)==B.charAt(i)){
                continue;
            }
            if(count==0&&A.charAt(i)!=B.charAt(i)){
                temp1 = i;
            }
            if(count==1&&A.charAt(i)!=B.charAt(i)){
                temp2 = i;
            }
            count++;
        }
        if(A.charAt(temp1)==B.charAt(temp2)&&A.charAt(temp2)==B.charAt(temp1)){
            return true;
        }
        return false;
    }
}
```
