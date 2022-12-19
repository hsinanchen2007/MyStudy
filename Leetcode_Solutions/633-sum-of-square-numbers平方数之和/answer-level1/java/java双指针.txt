```
public boolean judgeSquareSum(int c) {
        int sqc = (int)Math.sqrt(c);
        int fast = sqc;
        int slow = 0;
        int sum = 0;
        while(slow <= sqc && slow >= 0){
            sum = slow*slow + fast*fast;
            if(sum == c){
                return true;
            }else if(sum < c){
                slow++;
            }else{
                fast--;
            }
        }
        return false;
    }
```
