```
class Solution {
    public int findNthDigit(int n) {
        
        int digit = 1;
        int mag = 1;
        //int会溢出
        long base = 9;
        while(n>base){            
            mag *= 10;
            digit++;
            n -=base;
            base = 9L * mag * digit;
        }
        
        if(n%digit==0){
            return (mag + n/digit -1)%10;
        }
        int target = mag + n/digit;
        int m = digit-n%digit;
        while(m>0){
            target/=10;
            m--;
        }
        return target%10;
        
    }
}
```
