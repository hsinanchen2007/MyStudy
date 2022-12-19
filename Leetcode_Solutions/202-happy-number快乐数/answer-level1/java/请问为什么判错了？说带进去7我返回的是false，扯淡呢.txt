```
class Solution {
    static int times = 1;
    public boolean isHappy(int n) {
        int temp = 0;
        int count = 0;
        while(n > 0){
            temp = n % 10;
            count += temp*temp;
            n = n / 10;
        } 
        times++;
        if(times >= 100){
            return false;
        }     
        return count == 1 ? true : isHappy(count);
    }
}
```
