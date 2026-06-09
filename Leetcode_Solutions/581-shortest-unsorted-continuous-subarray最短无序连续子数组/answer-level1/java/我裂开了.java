### 解题思路
执行用时 :
13 ms
, 在所有 Java 提交中击败了
29.09%
的用户
内存消耗 :
40 MB
, 在所有 Java 提交中击败了
97.00%
的用户

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
         int [] sort_nums=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            sort_nums[i]=nums[i];
        }
        Arrays.sort(sort_nums);
        int start=0;
        int end=0;
        boolean isfindstart=false;
        boolean isfindend=false;
        for(int i=0;i<nums.length;i++){
            int j=nums.length-1-i;
            if(nums[i]!=sort_nums[i]&&isfindstart==false){
                start=i;
                isfindstart=true;
            }
            if(nums[j]!=sort_nums[j]&&isfindend==false){
                end=j;
                isfindend=true;
            }
            if(isfindstart==true&&isfindend==true){
                break;
            }
        }
        if(end==start){
            return 0;
        }
        return end-start+1;

    }
}
```