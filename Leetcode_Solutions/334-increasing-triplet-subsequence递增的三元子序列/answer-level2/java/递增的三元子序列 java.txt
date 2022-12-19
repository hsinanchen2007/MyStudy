### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int minnum=Integer.MAX_VALUE;
        int secnum=Integer.MAX_VALUE;
        for (int i:nums){
            if(i<=minnum){
                minnum=i;
                //secnum=Integer.MAX_VALUE;
            }
            else if(i<=secnum){
                secnum=i;
            }
            else{
                return true;
            }
        }
        return false;

    }
}
```