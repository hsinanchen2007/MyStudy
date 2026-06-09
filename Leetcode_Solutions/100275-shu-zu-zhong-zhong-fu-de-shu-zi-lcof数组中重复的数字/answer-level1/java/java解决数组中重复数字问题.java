### 解题思路
1.使用HashSet用于数字判重
2.指针i在for循环外部申请，方便最后返回结果数字
3.set添加时发生重复，就直接break循环，返回结果
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> visited=new HashSet<Integer>();
        int i=0;
        for(;i<nums.length;){
            if(!visited.add(nums[i])){
                break;
            }
            i++;
        }
        return nums[i];
    }
}
```