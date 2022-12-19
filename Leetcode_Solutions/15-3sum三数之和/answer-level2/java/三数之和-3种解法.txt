欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 3)，其中n为nums数组的长度。
空间复杂度是O(1)。

在LeetCode中提交会超时。

```java
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> listList = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] > 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] > 0) {
                        break;
                    }
                    if (k > j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        List<Integer> list = new ArrayList<>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[k]);
                        listList.add(list);
                    }
                }
            }
        }
        return listList;
    }
}
```

# 解法二：哈希表

利用哈希表记录每个数字出现的次数。

时间复杂度是O(n ^ 2)，其中n为nums数组的长度。
空间复杂度是O(n)。

执行用时：268ms，击败10.12%。消耗内存：49.2MB，击败85.36%。

```java
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> listList = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        //考虑3个0的情况
        if (map.containsKey(0) && map.get(0) >= 3) {
            addToListList(0, 0, 0, listList);
        }
        List<Integer> list = new ArrayList<>(map.keySet());
        Collections.sort(list);
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (list.get(i) * 2 + list.get(j) == 0 && map.get(list.get(i)) >= 2) {
                    addToListList(list.get(i), list.get(i), list.get(j), listList);
                }
                if (list.get(i) + list.get(j) * 2 == 0 && map.get(list.get(j)) >= 2) {
                    addToListList(list.get(i), list.get(j), list.get(j), listList);
                }
                int num = -list.get(i) - list.get(j);
                if (num > list.get(j) && map.containsKey(num)) {
                    addToListList(list.get(i), list.get(j), num, listList);
                }
            }
        }
        return listList;
    }

    private void addToListList(int num1, int num2, int num3, List<List<Integer>> listList) {
        List<Integer> list = new ArrayList<>();
        list.add(num1);
        list.add(num2);
        list.add(num3);
        listList.add(list);
    }
}
```

# 解法三：双指针

内层循环采用双指针遍历的形式。

时间复杂度是O(n ^ 2)，其中n为nums数组的长度。
空间复杂度是O(1)。

执行用时：79ms，击败62.77%。消耗内存：55.8MB，击败71.63%。

```java
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> listList = new ArrayList<>();
        Arrays.sort(nums);  //排序是前提
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[left]);
                    list.add(nums[right]);
                    listList.add(list);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (nums[i] + nums[left] + nums[right] < 0) {
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
        return listList;
    }
}
```