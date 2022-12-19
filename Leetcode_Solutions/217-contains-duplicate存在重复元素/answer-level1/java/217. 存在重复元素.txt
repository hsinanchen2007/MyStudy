/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/28
 *
 * 解题思路：哈希 不解释
 */
```
public boolean containsDuplicate(int[] nums) {
        HashMap<Integer , Integer> hashMap = new HashMap<Integer,Integer>();

        for(int i = 0; i < nums.length;i++){
            if(hashMap.containsKey(nums[i])){
                return true;
            }else{
                hashMap.put(nums[i],1);
            }
        }
        return false;
    }
```