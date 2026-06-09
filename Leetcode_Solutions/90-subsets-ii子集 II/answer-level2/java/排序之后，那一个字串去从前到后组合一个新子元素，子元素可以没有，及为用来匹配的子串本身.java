### 解题思路

【】 ===》【】【0】，【】【1】，【】【2】，【】【3】.。。。。
          【】【0】==》 【】【0】【1】，【】【0】【2】，【】【0】【3】
                       【】【0】【1】==》【】【0】【1】【3】，【】【0】【1】【4】

### 代码

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {

        List<List<Integer>> lists = new ArrayList<>();
        Arrays.sort(nums);
        getAllZiJi(nums,lists,0,new ArrayList<>());
        return lists;
    }
    private void getAllZiJi(int[] nums, List<List<Integer>> lists,int start,List<Integer> temp){
        temp=new ArrayList<>(temp);
        lists.add(temp);
        for (int i=start;i<nums.length;i++){
            if(i>start&&nums[i]==nums[i-1]){continue;}
            Integer integer = nums[i];
            temp.add(integer);
            getAllZiJi(nums,lists,i+1,temp);
            temp.remove(temp.size()-1);
        }
    }
}
```