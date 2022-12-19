自己突然想出来的一个方法，不知道这算是什么算法，但试了试确实能用。
可能做了很多多余的步骤。
总之大概思想就是这样：
        1. 从后往前，三个数为一组来判断 `prives[i], prives[i - 1], prives[i - 2]`。
        2. 因为从后往前判断，所以如果` prives[i]` 大于其他两个的话那么就代表赚了，所以相减取差最大的就好了。 

```java
 class Solution {
    public int maxProfit(int[] prives) {
        int i = prives.length - 1;
        int maxP = 0 ;
        // 如果只有两个那么直接判断返回。
        if(prives.length == 2 && prives[1] > prives[0]) { 
            maxP = (prives[1] - prives[0]);
            return maxP;
        }
         for(;i >= 1; i--) {
            // 因为方法是三个一组判断，所以如果只剩下最后两个的话就要另说了。
             if(i == 1) {   
                if(prives[i] > prives[i - 1]) {
                    maxP += (prives[i] - prives[i - 1]);
                
                }   
                break;
             }
            // 挑三个里面后面的两个判断谁最大，再判断前两个谁最小。
            if (prives[i] > prives[i - 1]) {    
                maxP += prives[i - 1] > prives[i - 2] ? (prives[i] - prives[i-2]) : (prives[i] - prives[i - 1]);
            }else if(prives[i - 1] > prives[i - 2]){
                maxP += (prives[i - 1] - prives[i - 2]);
            }
            // i要减2次，因为是三个一组所以要跳过中间的那一个。
            i--;
        }

        return maxP;
    }
}
```
执行用时：1 ms
内存消耗：41.9 MB