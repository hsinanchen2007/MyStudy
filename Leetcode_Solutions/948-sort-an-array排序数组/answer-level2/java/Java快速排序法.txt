### 解题思路
此处撰写解题思路
java快速排序法
关键点：代码思路容易理解，但具体的边界条件需要重点研究。
key为快排的判断数字。s e 为数组中移动判断的头尾指针。s<e的条件下，就需要不断地判断s和e
时刻记住nums[e]、nums[s]和key的判断需要注意s时刻小于e的条件。
### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        if(nums==null || nums.length==0) return null;
        quickSort(nums,0,nums.length-1);
        return nums;
    }
    public void quickSort(int[]nums,int start,int end){
        if(start>=end) return;
        int key=nums[start];
        int s=start,e=end;
        while(s<e){
            while(s<e && nums[e]>=key) e--;
                if(s<e) nums[s++]=nums[e];
            while(s<e && nums[s]<key) s++;
                if(s<e) nums[e--]=nums[s];
        }
        nums[s]=key;
        quickSort(nums,start,s-1);
        quickSort(nums,s+1,end);
        
    }
}
```