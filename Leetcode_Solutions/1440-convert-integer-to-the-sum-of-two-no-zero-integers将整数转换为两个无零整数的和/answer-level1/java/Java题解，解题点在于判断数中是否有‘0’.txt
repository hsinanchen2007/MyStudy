```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int i = 0;//第一个数
        int j = 0;//第二个数
        
        for(i = 1;i <= n/2;i++){
            if(!fun(i)) continue;
            j = n - i;
            if(fun(j)) break;
        }
        
        return new int[]{i,j};
    }
    
    private boolean fun(int num){
        if(num % 10 == 0) return false;
        
        while(num != 0){
            num /= 10;
            if(num != 0 && num % 10 == 0) return false;
        }
        
        return true;
    }
}
```
