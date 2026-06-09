### 解题思路
宽度优先搜索
值得注意的是，用Set来记录遍历过的下标。

### 代码

```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        if(arr[start] == 0)
            return true;
        List<Integer> list = new ArrayList<>();
        list.add(start);
        Set<Integer> set = new HashSet<>();
        set.add(start);
        while (list.size() != 0){
            int len = list.size();
            while (len-- != 0){
                Integer remove = list.remove(0);
                int right = remove + arr[remove];
                int left = remove - arr[remove];
                if (right < arr.length && !set.contains(right)){
                    list.add(remove + arr[remove]);
                    set.add(right);
                    if (arr[right] == 0)
                        return true;
                }
                if (left >= 0 && !set.contains(left)){
                    list.add(remove - arr[remove]);
                    set.add(left);
                    if (arr[left] == 0)
                        return true;
                }
            }
        }
        return false;
    }
}
```