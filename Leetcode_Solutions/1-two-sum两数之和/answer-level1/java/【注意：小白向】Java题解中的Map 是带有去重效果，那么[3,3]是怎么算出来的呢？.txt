```
class Solution {
    public int[] twoSum(int[] nums,int target){
    
        Map<Integer,Integer> map = new HashMap<>() ;
        for (int i = 0 ; i < nums.length ; i++){
            map.put(nums[i],i) ;
        }
        for(int j= 0; j < nums.length ; j++){
            int num = target - nums[j] ;
            if(map.containsKey(num) && map.get(num) != j){
               return new int[]{j,map.get(num)};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
```





这段代码我们从官方题解中也能看到类似的答案。

利用【3，3】- 6 、【2，5，5，10】- 10 来测试

我们通常一看觉得非常有道理，但是细琢磨又觉得有点不对。难道HashMap没有去重效果吗？
答案：有的，而且只会保留最后一次“3”或者“5”的角标位置。

map 最终形态（key-value） 

```
map1: {3:1} 

map2: {
        2:0,
        5:2,
        10:3,
    }
```



当我们第二次for循环的时候，我们从【3，3】中会遍历到第一个“3”(index:0)，通过target-nums[j] 可以推算出 num=3 ，再去map中寻找,找到的是{3:1}(记录的是最后一个“3”出现的位置）,index=1，找到的就是下一个“3”的位置，这样的话输出的就是【0，1】。
