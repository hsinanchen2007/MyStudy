常规思路：遍历数组`arr`，使用`Set`存储`arr`中的数。然后再次遍历`arr`，对于每个数判断其两倍数是否存在于`Set`中，如果存在则返回`true`，如果遍历结束未找到则返回`false`。
这道题需要注意的一个点是0的两倍数是其本身，因此如果直接用上述思路，遇到元素0只出现一次的时候就会出错。因此在使用`Set`存储的时候需要事先判断0，如果发现有多于一个0，则直接返回`true`。之后在第二次遍历`arr`的时候，只对非0数判断其两倍数是否存在于`Set`中。
```
class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> set = new HashSet<Integer>();
        for (int num : arr) {
            if (num != 0)
                set.add(num);
            else {
                if (!set.add(num))
                    return true;
            }
        }
        for (int num : arr) {
            if (num != 0 && set.contains(num * 2))
                return true;
        }
        return false;
    }
}
```
