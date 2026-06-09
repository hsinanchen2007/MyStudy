### 解题思路
1.可以简单地使用两个循环，第一层找到一个，第二层循环匹配，找到两数之和等于target即可，然后返回坐标。
2.使用哈希表
新定义一个哈希表 Map<Integer,Integer>map=new HashMap<>();
想象一下这个思路，遍历数组nums[]中每一个元素，用target与之相减得到一个中间值temp，
每一次相减后就去哈希表中查找（使用map.containsKey(temp)）有没有和中间值temp一样的元素，
如果有就返回它的下标和遍历数组中与target相减元素的下标i即可；如果没有，把这个nums[i]
使用map.put(nums[i],i)放到哈希表中，继续遍历数组查找。
遍历完成以后都没有的话就返回-1，-1即可，return new int[]{-1,-1};

### 代码

```java
//暴力解法，不动脑子版本
class Solution {
    public int[] twoSum(int[] nums, int target) {
     
       for(int i=0;i<nums.length;i++){    //第一圈循环
            for(int j=i+1;j<nums.length;j++)   //第二圈循环和第一圈循环中的每一个数字相加
           if(nums[i]+nums[j]==target){    //判断大小是否和target匹配
               return new int[]{i,j};   //匹配返回相应的下标即可
           }
       }

       return new int[]{-1,-1};   //失败

    }
}

//哈希表版本
class Solution {
    public int[] twoSum(int[] nums, int target) {
       Map<Integer,Integer>map=new HashMap<>();//定义一个哈希表

       for(int i=0;i<nums.length;i++){      //遍历循环数组
           int temp=target-nums[i];         //每循环一次就确定一次中间值
           if(map.containsKey(temp)){       //查询哈希表中是否有和中间值大小相同的元素
               return new int[]{map.get(temp),i};  //有的话返回哈希表中元素下标和数组相应数字下标
           }
           map.put(nums[i],i);    //哈希表中没有相应大小的元素就把num[i]放入哈希表
       }

       return new int[]{-1,-1};    //查找失败

    }
}
```

```kotlin
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {  //定义一个方法 返回值是Int数组类型
        var complement:Int 
        val map = hashMapOf<Int, Int>()   //定义哈希表
        for(i in nums.indices){ //循环遍历nums数组
            complement = target-nums[i]   //用目标值和nums数组中元素相减
            if(map.containsKey(complement)){  //判断哈希表中是否有相减值 complement
                return intArrayOf(map[complement]!!.toInt(),i)  //如果有的话返回相应的下标
            }
            map[nums[i]] = i    //如果没有  把数组nums[i]中遍历到的元素放入到哈希表中
        }
        return intArrayOf()

    }
}```