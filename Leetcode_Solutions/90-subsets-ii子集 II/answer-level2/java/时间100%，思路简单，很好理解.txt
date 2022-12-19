### 时间100%
看到写题解的人不多，就来凑凑热闹，解法很简单，去重就好了

![图片.png](https://pic.leetcode-cn.com/bded4cd99b62f6d66d635e56f28e086cbdd35746845c5f80f2ef691f064e8c88-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<Integer> sub = new ArrayList();
        List<List<Integer>> res = new ArrayList();
        Arrays.sort(nums);
        backTrack(nums,0,sub,res);
        return res;
    }

    public void backTrack(int[] nums,int i,List<Integer> sub,List<List<Integer>> res){
        res.add(new ArrayList(sub));
        for(int j = i;j < nums.length;j++){
            //这里去重
            if(j-1 >= i && nums[j] == nums[j-1]){
                continue;
            }
            sub.add(nums[j]);
            // if(!res.contains(sub)){
            //     res.add(new ArrayList(sub));
            // }
            backTrack(nums,j+1,sub,res);
            sub.remove(sub.size()-1);
        }
    }
}
```