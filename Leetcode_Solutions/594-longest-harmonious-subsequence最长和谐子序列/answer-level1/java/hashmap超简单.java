### 解题思路
此处撰写解题思路
找到每个元素出现的次数，然后在map中找是不是存在大于1的元素，如果存在，结果就是这两个元素的value值相加中的最大值。so easy~
### 代码

```java
class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer,Integer>hashmap=new HashMap<>();
        for(int num:nums)
        hashmap.put(num,hashmap.getOrDefault(num,0)+1);
        int result=0;
        for(int h:hashmap.keySet()){
            if(hashmap.containsKey(h+1)){
                result=Math.max(result,hashmap.get(h)+hashmap.get(h+1));
            }
        }
        return result;
    }
}
```