### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int res = 0;int value = 0,getMax = 0;
        for(int i = 0;i < customers.length;i++){
            if(i >= X){
                getMax = Math.max(getMax,value);
                if(grumpy[i - X] == 1) value -= customers[i - X];
            }
            if(grumpy[i] == 0) 
                res+=customers[i];
            else 
                value += customers[i];
        }
        getMax = Math.max(getMax,value);
        return res+getMax;
    }
}
```