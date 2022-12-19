一个略奇葩的解法，大体思路是先把原数组备份下来，然后对原数组排序，然后对排序的数组遍历，在每次遍历中都使用二分查找，寻找到和的两个加数后再在备份数组中找到对应的索引。

本方法有一点要注意，题目要求不能重复使用同一索引，因此务必要保证二分查找可以遍历到所有剩余的元素，同时不陷入死循环。在这个方面本方法比HashMap法要复杂一些。
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] backup = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            backup[i]=nums[i];
        }
        Arrays.sort(nums);
        int[] ans = new int[2];
        outer: for(int i=0;i<nums.length;i++){
            int half = target-nums[i];
            int low = i, high = nums.length-1; // 如果low始终从0开始，用时是4ms
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid]==half){
                    if(mid==i) {
                        low+=1;   // 避免陷入死循环
                        continue; // 不能重复利用
                    }
                    ans[0]=mid<i?mid:i;
                    ans[1]=i>mid?i:mid;
                    break outer;
                }else if(nums[mid]>half){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        int ansIndex[] = {-1, -1};
        for(int i=0;i<nums.length;i++){
            if(backup[i]==nums[ans[0]] && ansIndex[0]==-1) ansIndex[0]=i;
            else if(backup[i]==nums[ans[1]] && ansIndex[1]==-1) ansIndex[1]=i;
            if(ansIndex[0]!=-1 && ansIndex[1]!=-1) break;
        }
        Arrays.sort(ansIndex);
        return ansIndex;
    }
}
```