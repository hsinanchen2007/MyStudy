# 思路
预处理：
1. 数组先升序排序。
2. 再构建HashMap，其中key为数值，value为LinkedList，其中LinkedList存储该数值在数组中的**下标**。
3. 再构建boolean数组判断该数值是否已被使用。

注意：
```java
//1
Arrays.sort(nums);

//2
HashMap<Integer, LinkedList<Integer>> map = new HashMap<>(len);
for (int i = 0; i < len; ++i)
    map.computeIfAbsent(nums[i], unused -> new LinkedList<>()).addLast(i);

//3
boolean[] selected = new boolean[len];
```
注意，由于在进行步骤2时，数组已升序排序，因此HashMap中所有value(即LinkedList)所记录的下标也是升序排序好的。

接下来就每次从数组中选1个最小的值(记为`num`)作为起点，然后判断`num + 1`, `num + 2`, ..., `num + k - 1`是否存在于数组中(利用HashMap判断)，一旦发现它们有其一不存在于数组中，则直接返回`false`。
```java
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        int len = nums.length;
        Arrays.sort(nums);
        HashMap<Integer, LinkedList<Integer>> map = new HashMap<>(len);
        for (int i = 0; i < len; ++i)
            map.computeIfAbsent(nums[i], unused -> new LinkedList<>()).addLast(i);
        boolean[] selected = new boolean[len];
        while (!map.isEmpty()) {
            for (int i = 0; i < len; ++i)
                if (!selected[i]) { //当前下标的值未被使用，则将其作为起点。
                    selected[i] = true; //将当前下标的值标记为 已使用
                    //操作map，模拟“标记当前下标的值 已使用”
                    LinkedList<Integer> list = map.get(nums[i]);
                    list.removeFirst();
                    if (list.isEmpty()) map.remove(nums[i]);

                    for (int j = 1; j < k; ++j) {
                        list = map.get(nums[i] + j);
                        if (list == null) return false; //在未使用的数中，nums[i] + j不存在。
                        selected[list.removeFirst()] = true;
                        if (list.isEmpty())
                            map.remove(nums[i] + j);
                    }
                }
        }
        return true;
    }
}
```
