**思路**
和TwoSum的思路类似，遍历数组，先将每个数的2倍存入一个Set里，
再判断Set里是否存在，如果存在就说明该数是之前某数的2倍，返回True
需要注意0本身就是自己的2倍，所以需要排除0的情况

**代码**
```
class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> set = new HashSet<>();
        for(int a : arr) {
            if(set.contains(a)) {
                return true;
            } else {
                set.add(a * 2);
            }
        }
        for(int a : arr) {
            if(a != 0 && set.contains(a)) {
                return true;
            } 
        }
        return false;
    }
}
```

**复杂度**
时间复杂度为O(n)
空间复杂度为O(n))
