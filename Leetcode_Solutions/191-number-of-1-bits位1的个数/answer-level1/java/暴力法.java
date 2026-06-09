```
public class Solution {
        int count = 0;
        for(int i =0 ;i < 32;i++){
            if((n & 1) != 0){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
}
```


循环右移n 或者1也行，逐一判断每一位。