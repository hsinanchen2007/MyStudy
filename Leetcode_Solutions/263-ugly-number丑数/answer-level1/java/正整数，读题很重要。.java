### 解题思路
正整数，读题很重要。

### 代码

```java
class Solution {
    public boolean isUgly(int num) {
         if(num<=0)
         {
             return false;
         }else if(num==1){
            return true;
        }
        while(true) {
            if (num % 2 == 0) {
                num = num >>1;
            }else if(num%3==0){
                num = num / 3;
            }else if(num%5==0){
                num=num/5;
            }else{
                if(num==1){
                    return true;
                }
                break;
            }
        }
        return false;
    }
}
```