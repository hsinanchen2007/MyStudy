### 解题思路
1.处理特殊情况返回值，数组为空，只有一个元素
2.遍历数组，将数组的值作为Map的key值，value作为统计值出现的次数
3.遍历Map，判断数组长度的一半和Map中每一个vlue的值，符合条件（value<mid）的value对应的key值就是要找的主要元素

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
            
          if(nums.length==0){
            return -1;
        }
        if (nums.length==1){
            return nums[0];
        }
        int count = 0;
        Map<Integer,Integer> map = new HashMap<>();
        for (int i=0;i<nums.length;i++){
            if(map.containsKey(nums[i])){
                int tem = map.get(nums[i]);
                map.put(nums[i],tem+1);
            }else{
                map.put(nums[i],1);
            }
        }
        int mid = nums.length/2;
        for (Integer key:map.keySet()) {
           if(mid < map.get(key)){
              return key;
           }else{
               count =-1;
           }
        }
        return count;

    }
}
```