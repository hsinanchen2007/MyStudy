```
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        // 利用ArrayList中的add(int index,E element)方法
        // 将指定的元素插入此列表中的指定位置，并向右移动当前位于该位置的元素（如果有）以及所有后续元素（将其索引加 1）。 
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < nums.length; i++){
            res.add(index[i], nums[i]);
        }
        int[] target = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            target[i] = res.get(i);
        }
        return target;
    }
}
```
