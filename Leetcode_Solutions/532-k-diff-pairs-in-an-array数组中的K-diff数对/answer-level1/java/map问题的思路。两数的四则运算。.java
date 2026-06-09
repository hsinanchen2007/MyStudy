```
class Solution {
    public int findPairs(int[] nums, int k) {
        int count = 0 ;
        Map<Integer,Integer> map = new HashMap<>() ;
        if(k<0){
            return count ;
        }
        //首先想的是map键存储的值是什么，数组元素
        //value存储的是什么  是数组元素在数组中出现的次数。
        for(int i=0;i<nums.length;i++){
            map.putIfAbsent(nums[i],0) ;
            map.put(nums[i],map.get(nums[i])+1) ;
        }

        //遍历的逻辑分成两种情况k=0时，出现大于一次时 就是一种结果。
        //k!=0时，map中包含i+k的key时就是一种情况。
        for(int i:map.keySet()){
            if(k==0){
                if(map.get(i)>1){
                    count++ ;
                }
            }
            else if(k!=0){
                if(map.containsKey(i+k)){
                    count++ ;
                }
            }
        }
        return count ;
    }
}
```
这种两个数的和  两个数的差，涉及到两个数的时候  一定要想到map这种数据结构的。
然后确定逻辑
key存储什么
value存储什么
如何根据遍历keySet找到value的逻辑。