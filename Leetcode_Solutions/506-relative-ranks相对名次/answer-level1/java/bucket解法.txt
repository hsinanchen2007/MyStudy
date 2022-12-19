### 解题思路
放入桶中即可

### 代码

```java
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int[] hash=new int[144444];
        String[] res=new String[nums.length];
        int count=nums[0],index=1,bool=nums.length-3;
        for(int i=0;i<nums.length;i++){
            hash[nums[i]]=i;
        }
        for(int i=133333;i>=0;i--){
            if(i!=count && hash[i]==0){
                continue;
            }
            if(index<=3){
                if(index==1)
                res[hash[i]]="Gold Medal";
                if(index==2)
                res[hash[i]]="Silver Medal";
                if(index==3)
                res[hash[i]]="Bronze Medal";
                index++;
                continue;
            }
            res[hash[i]]=index+"";
            index++;
        }
        return res;
    }
}
```