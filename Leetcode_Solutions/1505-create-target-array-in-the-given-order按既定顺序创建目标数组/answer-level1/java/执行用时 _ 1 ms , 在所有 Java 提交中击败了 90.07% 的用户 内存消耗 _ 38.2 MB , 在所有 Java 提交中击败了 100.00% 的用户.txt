### 解题思路
用一个list循环遍历即可

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> list = new ArrayList<>();
        int[] ans = new int[index.length];
        for(int i = 0;i<index.length;i++){
            list.add(index[i],nums[i]);
        }
        for(int i = 0;i<list.size();i++){
            ans[i] = list.get(i);
        }
        return ans;
    }
}
```