### 解题思路1
要解此题最容易的方法就是靠暴力的方法，利用二重循环对nums[]进行嵌套遍历
如下代码
优点：简单易上手
缺点：O（n^2），牺牲了时间复杂度，实际应用性能低
### 代码
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int []res = new int[2];
        for(int i = 0;i<nums.length;i++)
        {
            for(int j = 0;j<nums.length;j++)
            {
                if(i!=j&&nums[i]+nums[j]==target)
                {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return new int[0];
    }
}
```

### 解题思路2
考虑到JAVA当中HashMap的特性
可以将nums中的key与value转化为HashMap中的键值对
以value作为HashMap中的key，以key作为HashMap中的value
为后面方便取出适合题意的两个数值的下标作铺垫
如下代码
优点：时间复杂度小，实际应用性能较高
缺点：好问题~！
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i = 0;i<nums.length;i++)
        {
            if(map.containsKey(target-nums[i]))
            {
                return new int[]{map.get(target-nums[i]),i};
            }
            map.put(nums[i],i);
        }
        return new int[0];
    }
}
```