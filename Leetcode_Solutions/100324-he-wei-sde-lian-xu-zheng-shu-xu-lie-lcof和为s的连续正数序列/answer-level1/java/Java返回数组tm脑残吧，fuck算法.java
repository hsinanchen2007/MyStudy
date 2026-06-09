### 解题思路
同向双指针

### 代码

```java
class Solution {
    //返回数组tm脑残吧，fuck算法
    public int[][] findContinuousSequence(int target) {
        if(target <= 2) {
            return null;
        }
        
        List<List<Integer>> results = new ArrayList<>();
        List<Integer> sub = new ArrayList<>();
        for(int i = 0; i <= target; i++) {
            sub.add(i);
        }
        
        int i = 1;
        int sum = i;
        for(int j = 2; j < target; j++) {
            sum += j;
        
            while(sum > target && i < j) {
                sum -= i;
                i++;
            }
            
            if(sum == target) {
                results.add(sub.subList(i, j + 1));
            }
        }
        
        
        //List转换为数组
        int[][] res = new int[results.size()][];
        for(int k = 0; k < results.size(); k++) {
            int[] subarr = new int[results.get(k).size()];
            for(int j = 0; j < results.get(k).size(); j++) {
                subarr[j] = results.get(k).get(j);
            }
            res[k] = subarr;
        }
        
        return res;
    }
}
```