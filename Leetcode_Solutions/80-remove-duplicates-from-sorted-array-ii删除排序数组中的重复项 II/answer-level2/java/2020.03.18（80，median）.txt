### 解题思路
本题用一层for循环完成

设定**计数器cnt=1**，满足题意的**总个数k**

从第二个元素开始遍历，如果和前面的数相等，那么计数器cnt++，不想等则是遇到新的元素，计数器从1开始计数

最后将计数器cnt<=2的元素放入新的索引位置k即可。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int k = 1;
        int cnt = 1;
        for(int i = 1 ; i < n; i++){//从第二个数开始遍历
            if(nums[i] == nums[i - 1]){//如果和前面的数有重复
                cnt++;
            }else{//如果不等则是遇到了新元素，那就对当前元素开始计数依次进行
                cnt = 1;
            }
            if(cnt <= 2){//只有重复元素个数不大于2的时候才将其放入新的索引位置
                nums[k++] = nums[i];
            }
        }      
        return k;
    }
}
```