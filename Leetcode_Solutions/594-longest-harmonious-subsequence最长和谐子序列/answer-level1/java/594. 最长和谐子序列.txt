/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/26
 *
 * 解题思路: 只需要计算出相邻的两个数的数字个数就行了 使用hashmap<数值,数量> 来完成
 */
```
 public int findLHS2(int[] nums) {
    HashMap<Integer,Integer> hashMap = new HashMap<>();
    int res = 0;
    for(int i = 0;i < nums.length;i++){
        hashMap.put(nums[i],hashMap.getOrDefault(nums[i],0) + 1);
    }

    for(int key : hashMap.keySet()){
        if(hashMap.containsKey(key + 1)){
            int c = hashMap.get(key) + hashMap.get(key + 1);
            res = Math.max(c , res);
        }

    }
    return res;
}
```