### 解题思路
这个应该不难把，数组的基本使用。

### 代码

```java
class Solution {
    public List<String> summaryRanges(int[] nums) {

        List<String> list = new ArrayList<>();
        if(nums.length == 0)
            return list;
        
        int start, end;
        int i = 1;

        for(start = 0, end = 1; end < nums.length;){
            if(nums[start] == nums[end] - i){
                end++;
                i++;
            }
            else{
                StringBuilder sb = new StringBuilder();
                if(i != 1){
                    sb.append(nums[start]);
                    sb.append("->");
                    sb.append(nums[end-1]);
                }
                else{
                    sb.append(nums[start]);
                }
                list.add(sb.toString());
                start = end;
                end += 1;
                i = 1;
            }
        }
        if(i == 1){
            StringBuilder sb = new StringBuilder();
            sb.append(nums[start]);
            list.add(sb.toString());
        }else{
            StringBuilder sb = new StringBuilder();
            sb.append(nums[start]);
            sb.append("->");
            sb.append(nums[end-1]);
            list.add(sb.toString());
        }
        return list;
    }
}
```