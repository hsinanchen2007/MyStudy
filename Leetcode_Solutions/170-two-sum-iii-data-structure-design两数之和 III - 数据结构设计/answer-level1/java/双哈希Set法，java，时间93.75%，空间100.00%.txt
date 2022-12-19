使用2个HashSet：
- all: 负责记录所有元素
- duplicate: 负责记录重复的元素

实现方法：
- add：如果all中已有该元素，则放入duplicate；否则放入all
- find：遍历all中的元素，寻找 `target = value - num` 是否存在。存在则找到。
 
但这里是否存在需要分为2种情况判断：
- `target == num`，则在重复元素集合duplicate中找；
- `target != num`，则在所有元素集合all中找。
 
2个HashSet即可解决是否存在2个相同元素之和为value的问题。

复杂度分析：n为已加入的元素个数，
- 时间复杂度：1次add为O(1)，1次find为O(n)
- 空间复杂度：O(n)


```
class TwoSum {

    private Set<Integer> all;
    private Set<Integer> duplicate;
    
    /** Initialize your data structure here. */
    public TwoSum() {
        all = new HashSet();
        duplicate = new HashSet();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        if (all.contains(number))
            duplicate.add(number);
        else
            all.add(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        int target;
        for (int num: all) {
            target = value - num;
            if (target == num && duplicate.contains(target))
                return true;
            if (target != num && all.contains(target))
                return true;
        }
        return false;
    }
}

```
