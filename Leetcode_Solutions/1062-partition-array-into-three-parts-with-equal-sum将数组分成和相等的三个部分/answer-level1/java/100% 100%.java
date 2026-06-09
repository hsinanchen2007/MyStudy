### 解题思路
明明感觉写的很乱，没想到两个100% [笑哭]]

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i=0;i<A.length;i++){
            sum += A[i];
        }
        if(sum%3!=0){
            return false;
        }
        int tar = sum/3;
        int cur = 0;
        int count = 0;
        for(int i=0;i<A.length;i++){
            cur += A[i];
            if(count!=2){
                if(cur==tar){
                    cur = 0;
                    count ++;
                    if(count==2 && i==A.length-1){
                        return false;
                    }
                }
            }
        }
        if(cur!=tar){
            return false;
        }
        return true;
    }
}


```