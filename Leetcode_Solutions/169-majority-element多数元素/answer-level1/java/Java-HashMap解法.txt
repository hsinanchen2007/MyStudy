### 解题思路
将数组元素放入hashmap，存放的时候将元素作为key，元素出现个数作为value，存map的时候出现一次key就将value值加一，最后找出map中value值最大的，把相应的key也取出来就行了。
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        //将元素放入map中
        Map<Integer,Integer> numsMap = new HashMap<>(nums.length);
        for (Integer item : nums){
            if(numsMap.containsKey(item)){
                int times = numsMap.get(item);
                numsMap.put(item,++times);
            }else{
                numsMap.put(item,1);
            }
        }
        //获取最大次数的元素
        int maxKey = -1;
        //获取最大元素的最大次数
        int maxValue = 0;
        for (Map.Entry<Integer,Integer> entry : numsMap.entrySet()){
            //获取最大值
            if(entry.getValue() > maxValue){
                maxValue = entry.getValue();
                maxKey = entry.getKey();
            }
        }
        //如果数组元素最大重复数小于 多数规则，返回失败
        if(maxValue <= nums.length/2){
            return -1;
        }
        return maxKey;
    }
}
```