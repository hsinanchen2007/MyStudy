### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck == null || deck.length == 0){
            return false;
        }
        int len = deck.length;
        Arrays.sort(deck);
        if(len == 2){
            if(deck[0] == deck[1]){
                return true;
            }
        }else{
            int mid = len / 2;
            for(int i = 2; i <= mid; i++){
                if(i != 2 && len % i != 0){
                    continue;
                }
                for(int j = 0; j < len; j = j + i){
                    if(j + i - 1 < len && deck[j] == deck[j+i-1]){
                        if(j + i - 1 == len - 1){
                            return true;
                        }
                        continue;
                    }else{
                        break;
                    }
                }

            }
            
        }
        return false;
    }
}
```