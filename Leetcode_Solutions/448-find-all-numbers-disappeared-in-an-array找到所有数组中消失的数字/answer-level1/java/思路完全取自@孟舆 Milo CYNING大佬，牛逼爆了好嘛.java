### 解题思路
执行用时 :
6 ms
, 在所有 java 提交中击败了
92.75%
的用户
内存消耗 :
47.9 MB
, 在所有 java 提交中击败了
91.60%
的用户

### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
       ArrayList<Integer> res=new ArrayList<>();
        int [] nums_copy=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            nums_copy[i]=nums[i];
        }
        for(int n=1;n<=nums.length;n++){
            if(nums_copy[nums[n-1]-1]>0){
                nums_copy[nums[n-1]-1]*=-1;
            }
        }
        for(int i=0;i<nums.length;i++){
            if(nums_copy[i]>0){
                res.add(i+1);
            }
        }
        return res;

        
    }
}
```