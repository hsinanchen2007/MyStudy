### 解题思路
一开始直接暴力dfs，不出意外的TLE。这时候就想剪枝试试，果断可以：
剪枝1:判断入队节点数是否超过了4个节点；
剪枝2:target < (4-k) * nums[now]，意思就是剩余可计入节点数是否能满足target，因为是之前处理成有序的数组，可以直接比较当前节点*剩余可加入节点数>targe就不能加了，反之就是比（4-k）*最后一个最大值。  这个剪枝能从3015ms直接加速到199ms。


![image.png](https://pic.leetcode-cn.com/2ce6c7010db0db0224c96c8837bb7dae186b28d66a847ebab099a5c6d649fb89-image.png)

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Set<List<Integer>> ok = new HashSet<>();
        List<Integer> ans = new ArrayList<>();
        
        for(int i = 0 ; i < nums.length; ++ i){
            ans.add(nums[i]);
        }
        Collections.sort(ans);
        for(int i = 0 ; i < nums.length; ++ i){
            nums[i] = ans.get(i);
        }
        find(ok, null, nums, 0, target, 0);

        return new ArrayList<>(ok);
    }

    public static void find(Set<List<Integer>> res, LinkedList<Integer> linkedList, int[] nums, int now, int target, int k){
        if(target == 0 && k == 4){
            if(res == null){
                res = new HashSet<>();
            }
            res.add(new ArrayList<>(linkedList));
        }
        if(k >= 4) return ;
        if(now > nums.length - 1) return ;
        //if(target < (4-k) * nums[now]) return ;
        //if(target > (4-k) * nums[nums.length - 1]) return ;
        for(int i = now ; i < nums.length; ++ i){
            if(linkedList == null){
                linkedList = new LinkedList<Integer>();
            }

            linkedList.addLast(nums[i]);
            find(res, linkedList, nums, i + 1, target - nums[i], k + 1);
            linkedList.removeLast();
        }


    }
}
```