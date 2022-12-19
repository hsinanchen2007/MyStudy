## [更多leetcode分类题解](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)
```
public boolean isUgly(int num) {
        if(num == 0){
            return false;
        }
        while (num != 1){
            if(num % 2 == 0){
                num /= 2;
                continue;
            }
            if(num % 3 == 0){
                num /= 3;
                continue;
            }
            if(num % 5 == 0){
                num /= 5;
                continue;
            }
            return false;
        }

        return true;
        
    }
```
