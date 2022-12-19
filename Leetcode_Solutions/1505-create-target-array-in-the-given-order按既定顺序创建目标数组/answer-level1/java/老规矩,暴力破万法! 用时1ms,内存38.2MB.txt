### 解题思路
1.日常判空处理
2.初始化返回数组,并赋值为-1
3.遍历数组,在target下标index[i]处插入nums[i]  (是插入,别写成替换了)
4.判断是否为-1(未使用的位置),如果该位置已被使用,则需依次后移一位
5.从后往前判断,依次将所插入元素后移一位,腾出位置给当前元素插入

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        if(nums == null || nums.length == 0){
            return nums;
        }

        int[] target = new int[nums.length];
        Arrays.fill(target, -1);
        int i = 0, j = i;

        for(; i < target.length; i++){
            if(target[index[i]] != -1){
                for(j = nums.length; j > index[i]; j--){
                    if(target[j - 1] != -1){
                        target[j] = target[j - 1];
                    }
                }
            }
            target[index[i]] = nums[i];
        }
        return target;
    }
}
```