### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingElement(int[] nums, int k) {
        List<Integer> list=new ArrayList<>();
        int j=0;
        int i=nums[0];
        int p=-1;
        if(k>nums[nums.length-1])
            return nums[0]+k+nums.length-1;
        while(i<=nums[nums.length-1]){
            if(nums[j]!=i){
                list.add(i);
                i++;
                p++;
            }
            else{
                i++;
                j++;
            }
            if(list.size()==k)
                return list.get(p);
        }
        return k-list.size()+nums[nums.length-1];
    }
}
```