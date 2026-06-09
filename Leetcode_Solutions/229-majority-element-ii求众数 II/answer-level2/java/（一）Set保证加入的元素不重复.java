### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> list = new ArrayList<Integer>();
        if(null==nums||0==nums.length){
            return list; 
        }
        int m = nums.length/3;
        Arrays.sort(nums);
        int count = 0;
        int num = nums[0];
        Set<Integer> set = new HashSet<Integer>();
        for(int i=0; i<nums.length;i++){
            if(nums[i]==num){
                count++;
                if(count>m){
                    set.add(num);
                }
            }else{
                if(count>m){
                    set.add(num);    
                }
                count=0;
                num=nums[i];
                i--;
            }
        }
        for(int i : set){
            list.add(i);
        }
        return list;
    }
}
```