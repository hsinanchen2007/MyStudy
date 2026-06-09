### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if(target < 3){
            int[][] ret = new int[0][0];
            return ret;
        }
        // 
        List<List<Integer>> list = new ArrayList<>();
        for(int i = 1; i <= target / 2; i++){
            int sum = 0;
            List<Integer> subList = new ArrayList<>();
            for(int j = i; j < target; j++){
                sum += j;
                subList.add(j);
                if(sum == target){
                    list.add(subList);
                    break;
                }
                if(sum > target){
                    break;
                }
            }
        }
        int[][] ret = new int[list.size()][];
        for(int i = 0; i < list.size(); i++){
            List<Integer> subList = list.get(i);
            ret[i] = new int[subList.size()];
            for(int j = 0; j < subList.size(); j++){
                ret[i][j] = subList.get(j);
            }
        }
        return ret;
    }
}
```