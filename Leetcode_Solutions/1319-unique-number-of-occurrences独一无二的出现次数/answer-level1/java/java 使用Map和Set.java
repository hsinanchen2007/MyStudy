### 解题思路
map记录元素的次数，set判断是否相同。

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer> map = new HashMap<>();
        Set<Integer> ans = new HashSet<>();
        for(int n : arr){
            map.put(n,map.getOrDefault(n,0)+1);
        }
        for(int n : map.keySet()){
            if(ans.contains(map.get(n))){
                return false;
            }
            ans.add(map.get(n));
        }
        return true;
    }
}
```