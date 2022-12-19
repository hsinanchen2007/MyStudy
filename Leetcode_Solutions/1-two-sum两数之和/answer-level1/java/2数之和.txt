### 解题思路
如果数组中存在重复的数字，则不能直接存入map中。
    1判断重复数字之和是否等于所需得和
        如果相等，直接返回。
        如果不等，继续存入
    2存入map中
    3根据map的特定进行遍历查询.
        如果map的键为target-nums[i]，则表明存在2数之和为target
    4遍历完成都不存在，抛出异常。


### 代码

```java

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map = new HashMap<Integer, Integer> ();

        for (int i = 0; i < nums.length; i++) {
            if(map.containsKey (nums[i]))
                if (nums[i]*2==target)
                    return new int[]{i,map.get (nums[i])};
            map.put (nums[i],i );
        }
        for (int i = 0; i < nums.length; i++) {
           if(map.containsKey (target-nums[i])&&map.get (target-nums[i])!=i){
               return new int[] {i,map.get (target-nums[i])};
           }
        }
        throw new IllegalArgumentException ("no two numbers");
    }
}
```