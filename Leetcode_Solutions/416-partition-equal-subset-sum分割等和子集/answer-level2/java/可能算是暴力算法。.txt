### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean Search(int start, int end, int[]nums, int target, HashSet<Integer>set){
        set.add(nums[0]);
        HashSet<Integer>set1=new HashSet<Integer>();
        if(nums[0]==target)return true;
        for(int j=1;j<end;j++){
            if(nums[j]==target)return true;
                for(Integer x:set){
                    set1.add(x+nums[j]);
                    if(x+nums[j]==target)
                        return true;
                }
            Iterator<Integer> iterator = set1.iterator();
                while(iterator.hasNext()){
                    set.add(iterator.next());
                    iterator.remove();
                }
                set.add(nums[j]);
            }
        return false;
    }
    public boolean canPartition(int[]nums) {
        Arrays.sort(nums);
        int len=nums.length;
        if(len<=1)return false;
        int mid=len/2;
        int sumn=0;
        for(int i=0;i<len;i++)
            sumn+=nums[i];
        int target=sumn/2;
        if(target*2!=sumn)return false;
        Set<Integer> set=new HashSet<Integer>();
        return Search(mid,len,nums,target, (HashSet<Integer>) set);

    }
}
```