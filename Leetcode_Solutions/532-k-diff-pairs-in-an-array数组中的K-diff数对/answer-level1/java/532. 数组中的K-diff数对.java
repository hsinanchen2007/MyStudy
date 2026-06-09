/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/23
 *
 * 解题思路1:排序 加上遍历
 *
 * 解题思路2:使用hash统计<数值,数值对应的个数>, 使用hashMap.KetSet遍历非重复数值, k==0: 数值对应的个数>=2 则 sum++; k > 0, （数值 + k）再hashMap中存在,sum++
 *
 */
```
public int findPairs2(int[] nums, int k) {
    Arrays.sort(nums);
    int sum = 0;
    for(int i =0; i < nums.length;i++){
        if(i > 0 && nums[i] == nums[i -1]) continue;
        for(int j = i +1 ;j < nums.length;j++){
            if(Math.abs(nums[i] - nums[j]) == k){
                sum ++;
                break;
            }
        }
    }
    return sum;
}

public int findPairs3(int[] nums, int k){

    int sum = 0;
    if(k < 0){
        return sum;
    }
    HashMap<Integer , Integer> hashMap = new HashMap<>();

    for(int i = 0; i < nums.length;i++){
        hashMap.put(nums[i],hashMap.getOrDefault(nums[i],0) + 1);
    }

    for(int i: hashMap.keySet()){
        if(k == 0){
            if(hashMap.get(i) > 1) sum ++;
        }else{
            if(hashMap.containsKey(i + k)){
                sum++;
            }
        }
    }

    return sum;

}
```