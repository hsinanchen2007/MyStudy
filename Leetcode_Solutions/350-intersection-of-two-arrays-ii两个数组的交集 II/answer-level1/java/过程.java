# 双重循环

肯定是一开始就是双重循环，先不管效率如何解出来再说，该方法效率确实最低，运行结果排名倒数，时间复杂度为O(n^2)

```java
public int[] intersect(int[] nums1, int[] nums2) {
    Integer[] aarray = new Integer[nums1.length];
    Integer[] barray = new Integer[nums2.length];
    int l = 0;
    for (int i = 0; i < nums1.length; i++) {
        int a = nums1[i];
        for (int j = 0; j < nums2.length; j++) {
            int b = nums2[j];
            if (a == b & 
                aarray[i] == null & 
                barray[j] == null) {
                l++;
                aarray[i] = a;
                barray[j] = b;
            }
        }
    }

    int[] array = new int[l];
    for (Integer b : barray) {
        if (b != null) {
            l--;
            array[l] = b;
        }
    }
    return array;
}
```


# 排序加双指针

第一种方法实在是太慢了，想了很久不知如何优化（没有经验），看到题目下的相关标签包含了`哈希表`,`排序`,`双指针`等，顺着这个思路想了想，排序和双指针可以并在一起用，这个效率确实高，时间复杂度基本上取决于排序的时间复杂度。

```java
public int[] intersect(int[] nums1, int[] nums2) {
    Arrays.sort(nums1);
    Arrays.sort(nums2);
    int i = 0;
    int j = 0;
    List<Integer> list = new ArrayList<>();
    while (true) {
        if (i > nums1.length - 1 || j > nums2.length - 1) {
            break;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            list.add(nums1[i]);
            i++;
            j++;
        }
    }
    int[] array = new int[list.size()];
    for (int k = 0; k < list.size(); k++) {
        array[k] = list.get(k);
    }
    return array;
}
```

# 哈希表

试了排序和双指针后还有哈希表的解法没有尝试，于是想到可以跟第一个解一样使用两个哈希表，但key是数字，值为出现的次数

```java
public int[] intersect(int[] nums1, int[] nums2) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i : nums1) {
        Integer c = map.get(i);
        map.put(i, c == null ? 1 : c + 1);
    }

    Map<Integer, Integer> map2 = new HashMap<>();
    List<Integer> list = new ArrayList();
    for (int i : nums2) {
        Integer c = map.get(i);
        if (c == null) continue;
        
        Integer c2 = map2.get(i);
        c2 = c2 == null ? 1 : c2 + 1;

        if (c2 > c) continue;

        map2.put(i, c2);
        list.add(i);
    }

    int[] array = new int[list.size()];
    int n = 0;
    for (int i : list) {
        array[n++] = i;
    }
    return array;
}
```