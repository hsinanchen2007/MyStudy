### 解题思路
把数组的值当做key，数组值出现的次数当做value存入hashmap里面
遍历hashmap找到值最大的

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(nums[i])){
               int temp= map.get(nums[i])+1;
               map.put(nums[i],temp);
            }else{
                map.put(nums[i],1);
            }
        }
        //便利hashmap找到出现次数最大的那个数
        Set<Integer> set=map.keySet();
        int max=0;
        int result=nums[0];
        for(Integer i:set){
            int temp=map.get(i);
            if(temp>max){
                max=temp;
                result=i;
            }
        }
        return result;
    }
}
```