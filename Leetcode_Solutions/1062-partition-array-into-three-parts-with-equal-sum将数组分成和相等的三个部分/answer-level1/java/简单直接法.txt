### 解题思路
求和并除以3，如果能整除，一次循环凑次数；若不能返回false

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i:A){
            sum += i;
        }
        if(sum%3 !=0) return false;
        sum/=3;
        int count = 0,temp =0;
        for(int i:A){
            temp += i;
            if(temp == sum){
                count++;
                temp = 0;
            }
        }
        
        return count >= 3;
    }
}
```