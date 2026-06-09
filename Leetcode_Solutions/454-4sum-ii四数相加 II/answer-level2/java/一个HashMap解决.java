### 解题思路
第一次循环将A B各项之和存入hashmap的key，value为出现次数；
第二次循环使用-C -D之和作为key去map中匹配，将匹配到的value加到结果上。

### 代码

```java
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for(int a:A){
            for(int b:B){
                map.put(a+b,map.getOrDefault(a+b,0)+1);
            }
        }
        for(int c:C){
            for(int d:D){
                if(map.containsKey(-c-d)){
                    count += map.get(-c-d);
                }
            }
        }
        return count;
    }
}
```