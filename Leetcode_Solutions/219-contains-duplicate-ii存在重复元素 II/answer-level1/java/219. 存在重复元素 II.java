
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/28
 *
 * 解题思路1： hashmap 将history 全部记录下来,若出现重复记录index最大的,因为题目要求差值最小
 *
 * 解题思路2：hashset 滑动窗口 详见图片
 */
![DDD4398224337C969B064788D8F68989.png](https://pic.leetcode-cn.com/e358190ee1c267cef7cd9ce053d227352456664f3693900987b98d6e31f47865-DDD4398224337C969B064788D8F68989.png)
```
public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer , Integer> hashMap = new HashMap<Integer,Integer>();

        for(int i = 0; i < nums.length;i++){
            if(hashMap.containsKey(nums[i])){
                if(Math.abs(hashMap.get(nums[i]) - i) <= k){
                    return true;
                }else{
                    hashMap.put(nums[i],i);
                }
            }else{
                hashMap.put(nums[i],i);
            }
        }
        return false;
    }

    public boolean containsNearbyDuplicate2(int[] nums, int k) {
        HashSet<Integer> hashSet = new HashSet<Integer>();

        for(int i = 0; i < nums.length;i++){

            //存在返回
            if(hashSet.contains(nums[i])) return true;

            hashSet.add(nums[i]);

            //移除最旧的
            if(hashSet.size() > k){
                hashSet.remove(nums[i - k]);
            }
        }
        return false;
    }
```
