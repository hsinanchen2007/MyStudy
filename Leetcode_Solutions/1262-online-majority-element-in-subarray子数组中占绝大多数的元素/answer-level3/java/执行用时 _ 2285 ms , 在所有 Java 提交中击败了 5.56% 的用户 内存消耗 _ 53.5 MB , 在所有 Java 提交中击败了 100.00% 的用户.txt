### 解题思路
map的key是元素，value是一个ArrayList，里面存的元素的index
执行query方法时，遍历map的keySet，对每一个元素的list进行遍历
list.get(p1)是大于等于left的下标
list.get(p2)是小于等于right的下标
p2-p1+1就是该元素在这个区间内出现的次数
如果大于等于threshold，则返回该元素的值

### 代码

```java
class MajorityChecker {
    HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
    public MajorityChecker(int[] arr) {
        for (int i=0; i<arr.length; i++) {
            ArrayList<Integer> list = map.get(arr[i]);
            if (list == null) {
                list = new ArrayList<Integer>();
            }
            list.add(i);
            map.put(arr[i], list);
        }
    }
    
    public int query(int left, int right, int threshold) {
        Set<Integer> set = map.keySet();
        for (Integer a : set) {
            ArrayList<Integer> list = map.get(a);
            int p1 = 0;
            int p2 = list.size() - 1;
            while (p1 < list.size() && list.get(p1) < left) p1++;
            while (p2 >= 0 && list.get(p2) > right) p2--;
            if (p2 - p1 + 1 >= threshold) {
                return a;
            } 
        }
        return -1;
    }
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker obj = new MajorityChecker(arr);
 * int param_1 = obj.query(left,right,threshold);
 */
```