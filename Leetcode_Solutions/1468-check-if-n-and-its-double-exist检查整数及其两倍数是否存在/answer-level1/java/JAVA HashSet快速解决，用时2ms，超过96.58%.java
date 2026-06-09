
![image.png](https://pic.leetcode-cn.com/56c3d1d4aa05b0482939f62d884d3c301d1273bd25680133d0a0ea090524f2ab-image.png)
联想到两数之和的解法：
维护一个HashSet集合，迭代数组中的元素，每次都在HashSet中查找是否存在有当前元素的值的两倍或者一半的元素。
如果有，则返回true, 否则的话就将当前元素添加到HashSet中。
迭代完成后，如果没有找到的需要的值，返回false；
```
    public boolean checkIfExist(int[] arr) {
        HashSet<Integer> set = new HashSet<>();
        for (int i : arr) {
            if (set.contains(2 * i) || (i % 2 == 0 && set.contains(i / 2)))
                return true;
            set.add(i);
        }
        return false;
    }
```
