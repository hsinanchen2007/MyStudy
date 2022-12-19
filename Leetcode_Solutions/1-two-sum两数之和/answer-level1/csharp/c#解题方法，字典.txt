使用字典对数据进行存储，字典存储的是当前这个数组元素所需要的差值，以及对应的序号。
进一步解释：如果我的target是9，当前数字是2，那么我需要的另外一个数字则是7，将这个7存储在字典中，如果在遍历数组的时候查询到字典中含有7这个数字，那么就将字典中存储的序号以及当前遍历的序号打印输出。
当然，在向字典中存储的时候要判断一下字典中是否存在这个差值了，如果已经存在了就不做更改。
```
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
       Dictionary<int,int> map=new Dictionary<int,int>();
       for(int i=0;i<nums.Length;++i){
           if(map.ContainsKey(nums[i])){
               return new int[2]{map[nums[i]],i};
           }
           else{
               if(!map.ContainsKey(target-nums[i])){
                    map.Add(target-nums[i],i);
               }
           }
       }
       return null;
    }
}
```
