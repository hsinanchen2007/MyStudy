### 解题思路
先统计每个数字的频次，然后验证出现次数是否唯一。

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Set<Integer> set = new HashSet<>();
        Map<Integer, Integer> map = calFre(arr);

        for(Integer i : map.values()){
            if(!set.add(i)) return false;
        }
        return true;
    }

    /**
     * 统计每个数字出现的频次
     * @param arr
     * @return
     */
    public static Map<Integer, Integer> calFre(int[] arr){
        Map<Integer, Integer> map = new HashMap<>();
        for(int i:arr){
            Integer num = map.get(i);
            map.put(i,num == null ? 1:num+1);
        }

        return map;
    }
}
```