两次循环，如果和2相除取余不是0就-1继续取，计数器加1，如果和2取余是0就继续除，计数器加1就行。

```
class Solution {
    public int numberOfSteps (int num) {
        int count = 0;
        while(num!=0){
            if(num%2!=0){
                num-=1;
                count++;
            }else{
                num=num/2;
                count++;
            }
        } 
        return count;
    }
}
```
