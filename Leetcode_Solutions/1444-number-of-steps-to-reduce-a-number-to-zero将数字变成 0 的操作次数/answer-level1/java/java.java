```
class Solution {
    public int numberOfSteps (int num) {
        for(int i =0;;i++) {
            if(num==2) {
                return i + 2;
            } else if (num%2==1){
                num = num-1;
            } else {
                num = num / 2;
            }
        }
    }
}
```

