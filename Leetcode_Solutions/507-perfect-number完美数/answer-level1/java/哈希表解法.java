### 解题思路


### 代码

```java
class Solution {
    public boolean checkPerfectNumber(int num) {
        if(num == 1)
            return false;
        int tmp = num - 1;
        HashMap<Integer, Integer> hashmap = new HashMap<>();
    
        for(int i = 2; i < num/2; i++){
            if(num % i == 0){
                if(!hashmap.containsKey(i) && !hashmap.containsKey(num/i)){
                    hashmap.put(i, 1);
                    hashmap.put(num/i, 1);
                    tmp = tmp - i;
                    tmp = tmp - num / i;
                }
            }
            if(tmp < 0)
                return false;
        }
        if(tmp == 0)
            return true;
        else
            return false;
    }
}
```