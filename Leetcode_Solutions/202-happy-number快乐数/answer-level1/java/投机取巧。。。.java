```
class Solution {
    public boolean isHappy(int n) {
        
        for(int i=0;i<50;i++){
            int a=0;
            while(n!=0){
                a=a+ (n%10)*(n%10);
                n=n/10;
            }
            if(a==1){
                return true;
            }
            else n=a;
        }
        return false;
    }
}
```
