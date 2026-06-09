### 解题思路
额，好像treemap搞定比较简单，天然排好序，只要第一个出现次数等于数组长度就是解
没有发现就是-1

### 代码

```java
import java.util.Map.Entry;
class Solution {
    public int smallestCommonElement(int[][] mat) {
        TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
        for(int i = 0; i < mat.length; i++){
            for(int j = 0; j < mat[0].length; j++){
                if(map.containsKey(mat[i][j])){
                    map.put(mat[i][j], map.get(mat[i][j]) + 1);
                }
                else{
                    map.put(mat[i][j], 1);
                }
            }
        }

        for(Entry<Integer, Integer> entry : map.entrySet()){
            if(entry.getValue() == mat.length){
                return entry.getKey();
            }
        }
        return -1;
    }
}
```