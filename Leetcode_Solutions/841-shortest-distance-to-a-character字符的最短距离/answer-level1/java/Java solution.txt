### 代码

```java
class RLC{
    int leftC = -1;
    int rightC = -1;
}

class Solution {
    public int[] shortestToChar(String S, char C) {
        Map<Integer, Integer> map = new HashMap<>();
        
        int len = S.length();
        RLC[] indexOfRLC = new RLC[len];
        for(int h = 0; h < len; h++){
            indexOfRLC[h] = new RLC();
        }
        int[] ans = new int[len];
        int countOfC = 0;
        map.put(0, -1);
        for(int i = 0; i < len; i++){
            if(S.charAt(i) == C){
                countOfC++;
                map.put(countOfC, i);
                ans[i] = 0; //To be clear, I know ans[] was initialized by 0s, this is for you to be clear
                indexOfRLC[i].leftC = 0;
                indexOfRLC[i].rightC = 0;
            }
        }
        map.put(countOfC + 1, len);
        
        for(int j = 1; j <= countOfC; j++){
            for(int k = map.get(j) - 1; k > map.get(j - 1); k--){
                indexOfRLC[k].leftC = map.get(j) - k;
            }
            for(int l = map.get(j) + 1; l < map.get(j + 1); l++){
                indexOfRLC[l].rightC = l - map.get(j);
            }
        }
        for(int m = 0; m < len; m++){
            if(indexOfRLC[m].leftC == -1){
                ans[m] = indexOfRLC[m].rightC;
            }
            else if(indexOfRLC[m].rightC == -1){
                ans[m] = indexOfRLC[m].leftC;
            }
            else if(indexOfRLC[m].rightC == 0 || indexOfRLC[m].leftC == 0){
                
            }
            else{
                ans[m] = indexOfRLC[m].rightC - indexOfRLC[m].leftC > 0 ? indexOfRLC[m].leftC : indexOfRLC[m].rightC;
            }
        }
        return ans;
        
        
        
    }
}
```