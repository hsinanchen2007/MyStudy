### 解题思路
单纯的暴力列举，就能双100%

### 代码

```java
class Solution {
    public int numTeams(int[] rating) {
        int len = rating.length;
        int ans = 0;
        //从rating[0]开始
        for(int i = 0; i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++){
                //当rating[i] > rating[j]
                if(rating[i] > rating[j]){
                    //且rating[j] > rating[k]
                    for(int k = j + 1; k < len; k++){
                       if(rating[j] > rating[k]){
                            ans++;
                       }
                    }
                }
                //当rating[i] < rating[j]
                else if(rating[i] < rating[j]){
                    for(int k = j + 1; k < len; k++){
                        //且rating[j] 《 rating[k]
                        if(rating[j] < rating[k]){
                            ans++;
                        }
                   }
                }
            }
        }
        return ans;
    }
}
```