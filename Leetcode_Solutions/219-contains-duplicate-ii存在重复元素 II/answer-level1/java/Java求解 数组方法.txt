![image.png](https://pic.leetcode-cn.com/dafa026c8fd530f51ebaf8a8c9c2d5d13b0fedd17ccf03cdf2e3b789cadba10f-image.png)

将给定数组排序，找到相同的数字，并将其索引依次放入新的数组Index中，只用比较Index中相邻的数的差是否大于k。

```
class Solution {
      public boolean containsNearbyDuplicate(int[] nums, int k) {
        boolean flag = false;
        int [] tem = nums.clone();
        Arrays.sort(tem);
        for(int i=0;i<tem.length-1;i++){
            if(tem[i]==tem[i+1]){
                flag = SearchIndex(tem[i],nums,k);
            }
        }
        return flag;
    }

    public boolean SearchIndex(int a,int [] nums,int k){
        boolean flag = false;
        ArrayList<Integer> Index = new ArrayList<Integer>();
        for (int i = 0;i<nums.length;i++){
            if (nums[i] == a){
                Index.add(i);
            }
        }
        for (int i=0;i<Index.size()-1;i++){
            if (Index.get(i+1)-Index.get(i)<=k){
                flag = true;
            }
        }
        return flag;
    }
}
```
