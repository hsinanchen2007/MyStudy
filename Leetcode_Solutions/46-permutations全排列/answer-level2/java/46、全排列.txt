## 解题思路
回溯：定义used[]，用于记录nums[]中的某个数是否已经使用过

## 代码

```java
class Solution {
    private List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> permute(int[] nums) {
        LinkedList<Integer> track = new LinkedList<>();
        boolean[] used = new boolean[nums.length];
        paiLie(nums, track, used);
        return res;
    }
    public void paiLie(int[] nums, LinkedList track, boolean[] used){
        if(track.size() == nums.length){
            res.add(new LinkedList(track));
            return;
        }
        for(int i = 0; i < nums.length; i ++){
            if(!used[i]){
                track.add(nums[i]);
                used[i] = true;
                paiLie(nums, track, used);
                track.removeLast();
                used[i] = false;
            }
        }
    }
}
```