
###注释
一开始没搞懂,最后的那个输入是什么意思,最后理解了return是输出数组中不重复元素的个数,然后只要把不重复的数据放在数据的最前面就好了.
### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
    int n =nums.length;
        int count =0;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]){
            count++;
            nums[count]=nums[i];
        }
    }
      return count+1;
       }
    }
```