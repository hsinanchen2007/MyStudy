### 解题思路
暴力O(n^3);险过；

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> res = new HashSet<List<Integer>>();
        List<Integer> myList = new LinkedList<>();
        int i=0,j=0,k=0;
        boolean bFlag = false;
        Arrays.sort(nums);
        for(i=0;i<nums.length;i++){
            if(nums[i]>0)break;
            if(bFlag)break;
            for(j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]>0)break;
                for(k=nums.length-1;k>j;k--){
                    if(-1*(nums[i]+nums[j])>nums[k])break;
                    if(nums[i]+nums[j]+nums[k]==0){
                        myList.add(nums[i]);
                        myList.add(nums[j]);
                        myList.add(nums[k]);
                        res.add(new LinkedList<>(myList));
                        myList.clear();
                        if(nums[i]==0&&nums[j]==0&&nums[k]==0){
                            bFlag = true;
                        }
                        break;
                    }
                }
            }
        }
        List<List<Integer>> resList = new ArrayList<>(res);
        return resList;
    }
}
```