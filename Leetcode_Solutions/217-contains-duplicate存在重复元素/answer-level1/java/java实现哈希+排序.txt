能想到的方法

# 1、暴力破解

用每个元素去和整个数组遍历比较，出现重复元素时返回true. 时间复杂度O(n^2).



## 2、哈希表筛选

新建哈希表存储数组元素，每次判断每个元素是否存在。时间复杂度O(n), 只遍历一次。但是哈希表每次判断其实也相当于一次遍历。

执行用时 :10 ms, 在所有 Java 提交中击败了56.11%的用户。

代码：

```java
public boolean containsDuplicate(int[] nums) {
    HashSet<Integer> set = new HashSet<Integer> ();
    for (int ele: nums){
        if (set.contains(ele)) return true;
        set.add(ele);
    }
    return false;
}
```



## 3、排序后判断

Arrays.sort将整个数组排序，然后判断是否有相邻元素重复。时间复杂度O(n).  

执行用时 :5 ms, 在所有 Java 提交中击败了89.60%的用户

代码：

```java
public boolean containsDuplicate(int[] nums) {
    Arrays.sort(nums);
    for (int i=1;i<nums.length;i++){
        if(nums[i-1]==nums[i]) return true;
    }
    return false;
}
```

