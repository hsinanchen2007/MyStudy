### 解题思路
此处撰写解题思路
遍历数组 查看HashMap中是否已经存在对应的key值(num[i]),如果不存在则将对应的key值nums[i]和键值1存入到HashMap中,如果已存在key值nums[i]则直接返回nums[i];
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(nums[i])){
                return nums[i];
            }else{
                map.put(nums[i],1);
            }
        }
        return -1;
    }
}
```