### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        int res = 2*n;
        HashMap<Integer, Integer[]> map = new HashMap<>();
        for(int[] set : reservedSeats){
            if(set[1] > 1 && set[1] < 10){
                if(!map.containsKey(set[0])){
                    map.put(set[0],new Integer[]{0,0,0,0});
                }
                map.get(set[0])[(set[1] - 2) / 2] = 1;
            }
        }
        for(int key:map.keySet()){
            Integer[] line = map.get(key);
            if(line[0] + line[1] + line[2] + line[3] == 0){
                continue;
            }else if(line[0] + line[1] == 0 ||  line[1] + line[2] == 0  ||  line[2] + line[3] == 0 ){
                res -= 1;
            }else{
                res -= 2;
            }
        }
        return res;
     }
}
```