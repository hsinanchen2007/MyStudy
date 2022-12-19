### 解题思路
利用Map中key不能重复将key-次数存入

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> m = new HashMap();
        for(int i:nums){
            m.put(i,(m.get(i)==null?0:m.get(i))+1);
        }
        for(int k:m.keySet()){
            if(m.get(k)>nums.length/2){
                return k;
            }
        }
        return 0;
    }
}
```