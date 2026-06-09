### 解题思路
双指针 唯一语言可以执行的 不给抛出时间超时

### 代码

```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        //  result = []
        // for k in range(len(nums)):
        //     i = 0
        //     for j in range(k+1,len(nums)):
        //         if nums[k]  > nums[j]:
        //             i += 1
        //             continue
        //     result.append(i)
        // return result
        int[] res = new int[nums.length];
        for(int k=0; k < nums.length;k++){
            int i =0;
            for(int j= k+1;j <nums.length;j++){
                if(nums[k] > nums[j]){
                    i++;
                    continue;
                }
            }
            res[k]= i;
        }
        return Arrays.stream(res).boxed().collect(Collectors.toList());
    }
}
```