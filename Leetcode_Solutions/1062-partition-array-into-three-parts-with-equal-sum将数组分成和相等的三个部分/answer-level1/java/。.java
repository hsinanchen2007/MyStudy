### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;        
        int count =0;        
        int a = 0;   
        for(int x : A){
            sum += x;
        }     
        if(sum % 3 != 0) return false;     
        sum /= 3;//求均值        
        for(int i = 0; i < A.length - 1; i++){           
            a += A[i];            
            if(a == sum){              //相等就记一次数，并且让a为0，重新计数。                
                count ++; 
                if(count == 2){
                    return true;
                }               
                a = 0;            
            }        
        }        
        return false; 
    }
}
```