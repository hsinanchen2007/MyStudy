欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 4)，其中n为nums数组的长度。
空间复杂度是O(1)。

执行用时：414ms，击败5.06%。消耗内存：48.5MB，击败27.31%。

```java
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> listList = new ArrayList<>();
        int n;
        if (null == nums || (n = nums.length) == 0) {
            return listList;
        }
        Arrays.sort(nums);
        for (int i = 0; i < n - 3; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {   //这个判断很重要，不然会超时
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 1] > target) {   //这个判断很重要，不然会超时
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                for (int k = j + 1; k < n - 1; k++) {
                    if (nums[i] + nums[j] + nums[k] + nums[k + 1] > target) {   //这个判断很重要，不然会超时
                        break;
                    }
                    if (k > j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }
                    for (int m = k + 1; m < n; m++) {
                        if (m > k + 1 && nums[m] == nums[m - 1]) {
                            continue;
                        }
                        if (nums[i] + nums[j] + nums[k] + nums[m] == target) {
                            addToListList(nums[i], nums[j], nums[k], nums[m], listList);
                        }
                    }
                }
            }
        }
        return listList;
    }

    private void addToListList(int num1, int num2, int num3, int num4, List<List<Integer>> listList) {
        List<Integer> list = new ArrayList<>();
        list.add(num1);
        list.add(num2);
        list.add(num3);
        list.add(num4);
        listList.add(list);
    }
}
```

# 解法二：哈希表

我们用一个哈希表来存储数组中出现的所有元素及其出现的次数。

总共分五种情况：

（1）四个数都相同。
（2）三个数相同。
（3）两个数相同，另外两个数也相同。
（4）两个数相同，另外两个数不相同。
（5）四个数都不相同。

时间复杂度是O(n ^ 3)，其中n为nums数组的长度。
空间复杂度是O(n)。 

执行用时：410ms，击败5.06%。消耗内存：65.1MB，击败6.17%。

```java
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> listList = new ArrayList<>();
        int n;
        if (null == nums || (n = nums.length) == 0) {
            return listList;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        // 4个数相同
        if (target % 4 == 0 && map.containsKey(target / 4) && map.get(target / 4) >= 4) {
            addToListList(target / 4, target / 4, target / 4, target / 4, listList);
        }
        List<Integer> list = new ArrayList<>();
        for (Integer integer : map.keySet()) {
            list.add(integer);
        }
        Collections.sort(list);
        // 3个数相同
        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (list.get(i) * 3 + list.get(j) == target && map.get(list.get(i)) >= 3) {
                    addToListList(list.get(i), list.get(i), list.get(i), list.get(j), listList);
                }
                if (list.get(i) + list.get(j) * 3 == target && map.get(list.get(j)) >= 3) {
                    addToListList(list.get(i), list.get(j), list.get(j), list.get(j), listList);
                }
            }
        }
        // 2个数相同+2个数相同
        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (list.get(i) * 2 + list.get(j) * 2 == target && map.get(list.get(i)) >= 2 && map.get(list.get(j)) >= 2) {
                    addToListList(list.get(i), list.get(i), list.get(j), list.get(j), listList);
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                for (int k = j + 1; k < list.size(); k++) {
                    // 2个数相同+2个数不同
                    if (list.get(i) * 2 + list.get(j) + list.get(k) == target && map.get(list.get(i)) >= 2) {
                        addToListList(list.get(i), list.get(i), list.get(j), list.get(k), listList);
                    }
                    // 2个数相同+2个数不同
                    if (list.get(i) + list.get(j) * 2 + list.get(k) == target && map.get(list.get(j)) >= 2) {
                        addToListList(list.get(i), list.get(j), list.get(j), list.get(k), listList);
                    }
                    // 2个数相同+2个数不同
                    if (list.get(i) + list.get(j) + list.get(k) * 2 == target && map.get(list.get(k)) >= 2) {
                        addToListList(list.get(i), list.get(j), list.get(k), list.get(k), listList);
                    }
                    // 4个数均不相同
                    int num = target - list.get(i) - list.get(j) - list.get(k);
                    if (num > list.get(k) && map.containsKey(num)) {
                        addToListList(list.get(i), list.get(j), list.get(k), num, listList);
                    }
                }
            }
        }
        return listList;
    }

    private void addToListList(int num1, int num2, int num3, int num4, List<List<Integer>> listList) {
        List<Integer> list = new ArrayList<>();
        list.add(num1);
        list.add(num2);
        list.add(num3);
        list.add(num4);
        listList.add(list);
    }
}
```

# 解法三：双指针

时间复杂度是O(n ^ 3)，其中n为nums数组的长度。
空间复杂度是O(1)。

执行用时：54ms，击败73.50%。消耗内存：40.3MB，击败77.12%。

```java
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> listList = new ArrayList<>();
        int n;
        if (null == nums || (n = nums.length) == 0) {
            return listList;
        }
        Arrays.sort(nums);
        for (int i = 0; i < n - 3; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {   //这个判断很重要，不然会很慢
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 1] > target) {   //这个判断很重要，不然会很慢
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = n - 1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        addToListList(nums[i], nums[j], nums[left], nums[right], listList);
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                    } else {
                        right--;
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }
        return listList;
    }

    private void addToListList(int num1, int num2, int num3, int num4, List<List<Integer>> listList) {
        List<Integer> list = new ArrayList<>();
        list.add(num1);
        list.add(num2);
        list.add(num3);
        list.add(num4);
        listList.add(list);
    }
}
```

# 解法四：两两成对考虑，并有Set集合来过滤除去重复元素

用一个哈希表存储数组中两个数的和，以及形成这个和可能的索引组合的List。虽然我们的Set集合能够自动帮我们过滤掉重复的List，但是过滤的前提是我们得到的List必须是有序的。比如(0, 1, -1, 0)和(0, 0, -1, 1)这一组数据，对于Set集合来说是不重复的，而(-1, 0, 0, 1)和(-1, 0, 0, 1)这组数据，对于Set集合来说才是重复的。

在形成哈希表的时候，我们能够保证第一个索引小于第二个索引，但是当我们在哈希表中寻找target - key的时候，如何保证两个索引数组形成的List是有序的呢？我们只需要让第一个数组的较大索引小于第二个数组的较小索引即可。

这个思路的时间复杂度分析挺复杂的。首先，排序过程的时间复杂度一定是O(nlogn)，其中n为nums数组的长度。而形成哈希表的时间复杂度是O(n ^ 2)级别的。而遍历哈希表形成结果的过程的时间复杂度不好算，这和每两个数的和对应的List的大小有关。而空间复杂度还是很明了的，我们存储了一个哈希表，而哈希表的键存的是两个数的和，这两个数的组合可能产生的和是O(n ^ 2)级别的，因此空间复杂度是O(n ^ 2)级别的。

执行用时：116ms，击败12.43%。消耗内存：65MB，击败6.17%。

```java
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Set<List<Integer>> listSet = new HashSet<>();
        int n;
        if (null == nums || (n = nums.length) == 0) {
            return new ArrayList<>();
        }
        Arrays.sort(nums);
        Map<Integer, List<Integer[]>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int num = nums[i] + nums[j];
                Integer[] pair = {i, j};    //保证了pair数组里i < j
                if (map.containsKey(num)) {
                    map.get(num).add(pair);
                } else {
                    List<Integer[]> list = new ArrayList<>();
                    list.add(pair);
                    map.put(num, list);
                }
            }
        }
        // 寻找组合
        for (Integer integer : map.keySet()) {
            if (map.containsKey(target - integer)) {
                List<Integer[]> list1 = map.get(integer);
                List<Integer[]> list2 = map.get(target - integer);
                for (Integer[] pair1 : list1) {
                    int index1 = pair1[0], index2 = pair1[1];
                    for (Integer[] pair2 : list2) {
                        int index3 = pair2[0], index4 = pair2[1];
                        if (index2 < index3) {  //防重复
                            List<Integer> list = new ArrayList<>();
                            list.add(nums[index1]);
                            list.add(nums[index2]);
                            list.add(nums[index3]);
                            list.add(nums[index4]);
                            listSet.add(list);
                        }
                    }
                }
            }
        }
        return new ArrayList<>(listSet);
    }
}
```

# 解法五：解法四的另一种实现方式

这个思路的时间复杂度分析挺复杂的。首先，排序过程的时间复杂度一定是O(nlogn)，其中n为nums数组的长度。而形成哈希表的时间复杂度是O(n ^ 2)级别的。而遍历哈希表形成结果的过程的时间复杂度不好算，这和每两个数的和对应的List的大小有关。而空间复杂度还是很明了的，我们存储了一个哈希表，而哈希表的键存的是两个数的和，这两个数的组合可能产生的和是O(n ^ 2)级别的，因此空间复杂度是O(n ^ 2)级别的。

执行用时：98ms，击败19.51%。消耗内存：53.5MB，击败11.70%。

```java
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Set<List<Integer>> listSet = new HashSet<>();
        int n;
        if (null == nums || (n = nums.length) == 0) {
            return new ArrayList<>();
        }
        Arrays.sort(nums);
        Map<Integer, List<Integer[]>> map = new HashMap<>();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int num = nums[i] + nums[j];
                Integer[] pair = {i, j};
                if (map.containsKey(num)) {
                    map.get(num).add(pair);
                } else {
                    List<Integer[]> list = new ArrayList<>();
                    list.add(pair);
                    map.put(num, list);
                }
            }
        }
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int tmp = target - nums[i] - nums[j];
                if (!map.containsKey(tmp)) {
                    continue;
                }
                List<Integer[]> list = map.get(tmp);
                for (Integer[] integers : list) {
                    if (integers[0] > j) {
                        List<Integer> retList = new ArrayList<>();
                        retList.add(nums[i]);
                        retList.add(nums[j]);
                        retList.add(nums[integers[0]]);
                        retList.add(nums[integers[1]]);
                        listSet.add(retList);
                    }
                }
            }
        }
        List<List<Integer>> listList = new ArrayList<>();
        for (List<Integer> list : listSet) {
            listList.add(list);
        }
        return listList;
    }
}
```