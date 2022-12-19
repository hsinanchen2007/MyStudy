第一种方法是采用HashMap，把nums中的每一个元素存入到Map中对应的value是各个元素出现的个数，最后遍历一遍找到最大的value，返回即可。
方法一：
```
Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for(int num: nums){
            if(!counts.containsKey(num)){
                counts.put(num, 1);
            }
            else{
                counts.put(num, counts.get(num) + 1);
            }
        }

        Map.Entry<Integer, Integer> majorityElement = null;
        for(Map.Entry<Integer, Integer>entry: counts.entrySet()){
            if(majorityElement == null || entry.getValue() > majorityElement.getValue()){
                majorityElement = entry;
            }
        }
        return majorityElement.getKey();
    }
```
第二种方法就是将数组sort一遍，当然，如果不使用sort函数自己定义sort，复杂度会更低，其中数量大于n/2的数一定会经过中间，返回nums[nums.length/2]一定会得到该数。
方法二：
```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```