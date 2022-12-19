方法一：两重循环，内层循环，每次从第一个元素开始，遍历到外层循环的前一个位置，并判断是否存在满足条件的数。
```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        for(int i = 1;i<nums.length;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] + nums[j] == target){
                    res[0] = j;
                    res[1] = i;
                    return res;
                }
            }
        }

        return null;
    }
}

```


方法二：hashmap。在for循环的过程中，同时构建hashmap，利用hashmap快速
查找的特点，省去了方法一中内层循环的时间。
```
class Solution {
    public int[] twoSum(int[] nums, int target) {

        int[] res = new int[2];
        HashMap<Integer,Integer> hashmap = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            int j = target - nums[i];
            if(hashmap.containsKey(j)){
                res[0] = hashmap.get(j);
                res[1] = i;
                return res;
            }
            hashmap.put(nums[i],i);
        }
        return null;
    }
}
```
