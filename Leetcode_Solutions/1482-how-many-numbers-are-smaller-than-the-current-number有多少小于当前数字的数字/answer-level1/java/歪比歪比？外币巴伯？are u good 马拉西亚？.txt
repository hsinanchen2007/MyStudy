### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int len=nums.length;
        int[] temp=new int[len];
        temp=Arrays.copyOf(nums,len);
        Arrays.sort(temp);
        
        Map<Integer,Integer> map=new HashMap<>();
        int p=0;
        map.put(temp[0],0);
        for (int i=0;i<=len-1;i++){
            if (temp[i]!=temp[p]){
                map.put(temp[i],i);
                p=i;
            }
                      
        }
        
        for (int i=0;i<len;i++){
            nums[i]=map.get(nums[i]);
        }
        return nums;
        
    }
}
```