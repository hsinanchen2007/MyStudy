### 解题思路
利用HashMap存储键值集的特性遍历数组元素来存储数值与下标，并循环校验与匹配补数。

### 时间复杂度
### O(n)
### 空间复杂度
### O(1)

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        //法一：利用HashMap存储结构的特性--推荐
        Map<Integer,Integer> numMap = new HashMap<Integer,Integer>();
        for(int i = 0; i < nums.length; i++){
            //如果numMap的key集中匹配到当前数字，则取出当前数字及numMap中的下标
            if(numMap.containsKey(nums[i])){
                res[0] = i;
                res[1] = numMap.get(nums[i]);
                return res;
            }
            //将当前数字的补数与下标存入numMap等待匹配
            numMap.put(target - nums[i],i);        
        } 
        //法二：暴力法--不推荐
        // for(int i = 0; i < nums.length; i++){
        //     for(int j = 0; j < nums.length; j++){
        //         if(nums[i] + nums[j] == target && i != j){
        //             res[0] = i;
        //             res[1] = j;   
        //         }    
        //     }
        //}    
        //若无匹配则返回空数组
        return new int[2];
    }  
}
```