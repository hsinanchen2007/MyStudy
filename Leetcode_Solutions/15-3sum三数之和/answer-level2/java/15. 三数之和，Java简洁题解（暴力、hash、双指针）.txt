# 审题
1. 返回不重复的三元组
2. 会有复数，无序
3. 可能不存在（实际要求返回空数组）
4. a+b=-c
5. 数组内有重复数字，结果有可能有重复

# 思路
1. 暴力：三重循环
2. hash：两重暴力+hash
3. 夹逼：因为不需要下标，可以排序后夹逼

# 反馈：
1. 通过一些边界条件，加速代码

# 问题：
1. 如何在hash很好的避免结果集重复？

# 代码实现
1. 暴力：超出时间限制
2. hash slow
3. 夹逼法
4. 夹逼快速版

## 1.暴力：超出时间限制

```java
/**
    * 暴力：超出时间限制
    * @param nums
    * @return
    */
private List<List<Integer>> directlySolution(int[] nums) {
    if (nums == null || nums.length <= 2) {
        return Collections.emptyList();
    }
    Arrays.sort(nums);
    Set<List<Integer>> result = new LinkedHashSet<>();
    for (int i = 0; i < nums.length; i++) {
        for (int j = i+1; j < nums.length; j++) {
            for (int k = j+1; k < nums.length; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    List<Integer> value = Arrays.asList(nums[i], nums[j], nums[k]);
                    result.add(value);
                }
            }
        }
    }

    return new ArrayList<>(result);
}
```

## 2.hash slow

```java
/**
    * hash slow
    * 1406 ms	46 MB
    *
    * @param nums
    * @return
    */
private List<List<Integer>> hashSolution(int[] nums) {
    if (nums == null || nums.length <= 2) {
        return Collections.emptyList();
    }
    Set<List<Integer>> result = new LinkedHashSet<>();

    for (int i = 0; i < nums.length - 2; i++) {
        int target = -nums[i];
        Map<Integer, Integer> hashMap = new HashMap<>(nums.length - i);
        for (int j = i + 1; j < nums.length; j++) {
            int v = target - nums[j];
            Integer exist = hashMap.get(v);
            if (exist != null) {
                List<Integer> list = Arrays.asList(nums[i], exist, nums[j]);
                list.sort(Comparator.naturalOrder());
                result.add(list);
            } else {
                hashMap.put(nums[j], nums[j]);
            }
        }
    }

    return new ArrayList<>(result);
}
```

## 3.夹逼法

```java
/**
    * 夹逼法
    * 899 ms	45.9 MB
    * @param nums
    * @return
    */
private List<List<Integer>> squeezeSolution(int[] nums) {
    if (nums == null || nums.length <= 2) {
        return Collections.emptyList();
    }
    Set<List<Integer>> result = new LinkedHashSet<>();

    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 2; i++) {
        int head = i + 1;
        int tail = nums.length - 1;
        while (head < tail) {
            int sum = -(nums[head] + nums[tail]);
            if (sum == nums[i]) {
                List<Integer> value = Arrays.asList(nums[i], nums[head], nums[tail]);
                result.add(value);
            }
            if (sum <= nums[i]) {
                tail--;
            } else {
                head++;
            }
        }
    }

    return new ArrayList<>(result);
}
```

## 4.夹逼法快速版

```java
/**
    * 夹逼快速版
    *
    * 18 ms	45.6 MB
    * @param nums
    * @return
    */
private List<List<Integer>> squeezeFastSolution(int[] nums) {
    if (nums == null || nums.length <= 2) {
        return Collections.emptyList();
    }
    List<List<Integer>> result = new LinkedList<>();

    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 2; i++) {
        // 加速1：c为非负数，就不能满足a+b+c=0了
        if (nums[i] > 0) {
            return result;
        }
        // 加速2：跳过计算过的数据，同时防止结果重复
        if (i != 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int head = i + 1;
        int tail = nums.length - 1;
        while (head < tail) {
            int sum = -(nums[head] + nums[tail]);
            if (sum == nums[i]) {
                result.add(Arrays.asList(nums[i], nums[head], nums[tail]));
                // 加速3：跳过计算过的数据，同时防止结果重复
                while (head < tail && nums[head] == nums[head+1]) {
                    head++;
                }
                while (head < tail && nums[tail] == nums[tail-1]) {
                    tail--;
                }
            }
            if (sum <= nums[i]) {
                tail--;
            } else {
                head++;
            }
        }
    }

    return result;
}
```

## 5.失败的加速hash，未解决去重

```java
 /**
    * 失败
    * @param nums
    * @return
    */
private List<List<Integer>> hashFastSolution(int[] nums) {
    if (nums == null || nums.length <= 2) {
        return Collections.emptyList();
    }
    List<List<Integer>> result = new LinkedList<>();
    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 2; i++) {
        if (nums[i] > 0) {
            return result;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int target = -nums[i];
        Map<Integer, Integer> hashMap = new HashMap<>(nums.length - i);
        for (int j = i + 1; j < nums.length; j++) {
            int v = target - nums[j];
            Integer exist = hashMap.get(v);
            if (exist != null) {
                result.add(Arrays.asList(nums[i], exist, nums[j]));
            } else {
                hashMap.put(nums[j], nums[j]);
            }
            while (j < nums.length && nums[j] == nums[j+1]) j++;
        }
    }

    return result;
}
```