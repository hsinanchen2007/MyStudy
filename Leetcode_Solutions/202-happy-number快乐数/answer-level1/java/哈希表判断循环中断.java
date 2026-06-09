### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public Boolean isHappy(int n){
        Set set = new HashSet();
        int sum ;
        while (true){
            sum = 0;
           while(n!=0) {
             sum += (n% 10) *(n%10);
               n = n / 10;
           }
           if (sum == 1){
               return true;
           }else {
             if (set.contains(sum)){
                 break;
             }
             set.add(sum);
             n=sum;
           }
        }
        return false;
    }
}
```