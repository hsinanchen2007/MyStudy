### 解题思路
key：存储值。value：存储下标
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) 
    {

        int len = numbers.length;
        Map<Integer,Integer> map = new HashMap<>();
        for(int i = 0; i < len; i++){
            if(map.containsKey(target - numbers[i])){ //，目标
                return new int[]{ map.get(target - numbers[i]) + 1, i + 1}; //位置从1开始的
            }
            map.put(numbers[i],i);
        }
        return null;
    }
}
```