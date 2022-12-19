
![TIM图片20191109173939.png](https://pic.leetcode-cn.com/09e2a37d1a3b9c6a41e593637ce0271f5a60b7df9574089490a766e635cb1ebe-TIM%E5%9B%BE%E7%89%8720191109173939.png)

这个方法其实是受**第873题. 最长的斐波那契子序列的长度** 的**官方题解**启发，在这个思路上写出来的。

# **思路：**
等差数列 其实在 **给定前2个数**之后，就能求出**整个等差数列**(虽说是**无限长**的)。
既然如此，那就不断地 **固定**等差数列的 **前2个数**，去判断：
下1个**理论值** 是否在数组A[]中 **且**(**&&**) 该**理论值**在数组A[]中的**下标** 要 **>** 等差数列的**最后1个实际值的下标**(即**理论值**的 **上1个值的下标**)。

# **具体实现：**
构建1个**HashMap**：数组A[]中的**值**作为**key**，**值**所对应的**下标** 去组成1个**ArrayList** 作为**value**。

# 线性查找代码
```java [-线性查找(无注释)]
class Solution {
    public int longestArithSeqLength(int[] A) {
        int len = A.length;
        Map<Integer, List<Integer>> map = new HashMap<>(len);
        for (int i = 0; i < len; ++i)
            map.computeIfAbsent(A[i], unused -> new ArrayList<>()).add(i);

        int res = 0, count = 2;
        for (int i = 0; i < len - res; ++i) {
            for (int j = i + 1; j < len - res + 1; ++j) {
                int diff = A[j] - A[i];
                if (diff == 0) {
                    res = Math.max(res, map.get(A[i]).size());
                    continue;
                }
                int next = A[j] + diff;
                int last_idx = j;
                search:
                while (map.containsKey(next)) {
                    List<Integer> temp_list = map.get(next);
                    for (int idx : temp_list) {
                        if (idx > last_idx) {
                            last_idx = idx;
                            ++count;
                            next += diff;
                            continue search;
                        }
                    }
                    break search;
                }
                res = Math.max(res, count);
                count = 2;
            }
        }
        return res;
    }
}
```
```java [-线性查找(有注释)]
class Solution {
    public int longestArithSeqLength(int[] A) {
        int len = A.length;
        //构建HashMap: key: 数的值， value: 由数在 数组A中的下标 所构成的ArrayList
        Map<Integer, List<Integer>> map = new HashMap<>(len);
        //遍历数组A并构造HashMap
        for (int i = 0; i < len; ++i)
            map.computeIfAbsent(A[i], unused -> new ArrayList<>()).add(i);

        //存储最终的结果
        int res = 0;
        //计数器，初始化为2(从2起步)
        int count = 2;
        //确定等差数列中的第1个数
        for (int i = 0; i < len - res; ++i) {
            //确定等差数列中的第2个数
            for (int j = i + 1; j < len - res + 1; ++j) {
                //计算等差数列的 差值
                int diff = A[j] - A[i];
                //若差值为0，则A[j]和A[i]相等，在HashMap中查找key为A[i]或A[j] 的value(ArrayList的长度，即下标的个数)
                if (diff == 0) {
                    //更新res的值
                    res = Math.max(res, map.get(A[i]).size());
                    //跳到下一次循环
                    continue;
                }
                //获取 当前等差数列中， 理论上的 下1个数的值
                int next = A[j] + diff;
                //记录 等差数列中，最后1个数的下标(初始化为j，即等差数列中第2个数的下标)
                int last_idx = j;
                //HashMap中 存在 当前等差数列， 下1个数的理论值
                search:
                while (map.containsKey(next)) {
                    //获取key为理论值的 value(ArrayList)
                    List<Integer> temp_list = map.get(next);
                    //遍历value(ArrayList)
                    for (int idx : temp_list) {
                        //若该值 > 等差数列中 最后1个值的下标
                        if (idx > last_idx) {
                            //更新last_idx(等差数列中 最后1个值的下标)
                            last_idx = idx;
                            //count + 1
                            ++count;
                            //计算 当前等差数列中， 理论上的 下1个数的值
                            next += diff;
                            continue search;
                        }
                    }
                    //未找到则break
                    break search;
                }
                //更新res的值
                res = Math.max(res, count);
                //count计数 重置为2(从2起步)
                count = 2;
            }
        }
        return res;
    }
}
```

为了使代码更短更简洁，就将**线性查找**修改为**二分查找**：

# 二分查找代码
```java [-二分查找(无注释)]
class Solution {
    public int longestArithSeqLength(int[] A) {
        int len = A.length;
        Map<Integer, List<Integer>> map = new HashMap<>(len);
        for (int i = 0; i < len; ++i)
            map.computeIfAbsent(A[i], unused -> new ArrayList<>()).add(i);

        int res = 0, count = 2;
        for (int i = 0; i < len - res; ++i) {
            for (int j = i + 1; j < len - res + 1; ++j) {
                int diff = A[j] - A[i];
                if (diff == 0) {
                    res = Math.max(res, map.get(A[i]).size());
                    continue;
                }
                int next = A[j] + diff, last_idx = j;
                while (map.containsKey(next)) {
                    List<Integer> temp_list = map.get(next);
                    last_idx = -(Collections.binarySearch(temp_list, last_idx) + 1);
                    if (last_idx == temp_list.size())
                        break;
                    last_idx = temp_list.get(last_idx);
                    ++count;
                    next += diff;
                }
                res = Math.max(res, count);
                count = 2;
            }
        }
        return res;
    }
}
```
```java [-二分查找(有注释)]
class Solution {
    public int longestArithSeqLength(int[] A) {
        int len = A.length;
        //构建HashMap: key: 数的值， value: 由数在 数组A中的下标 所构成的ArrayList
        Map<Integer, List<Integer>> map = new HashMap<>(len);
        //遍历数组A并构造HashMap
        for (int i = 0; i < len; ++i)
            map.computeIfAbsent(A[i], unused -> new ArrayList<>()).add(i);
        //存储最终的结果
        int res = 0;
        //计数器，初始化为2(从2起步)
        int count = 2;
        //确定等差数列中的第1个数
        for (int i = 0; i < len - res; ++i) {
            //确定等差数列中的第2个数
            for (int j = i + 1; j < len - res + 1; ++j) {
                //计算等差数列的 差值
                int diff = A[j] - A[i];
                //若差值为0，则A[j]和A[i]相等，在HashMap中查找key为A[i]或A[j] 的value(ArrayList的长度，即下标的个数)
                if (diff == 0) {
                    //更新res的值
                    res = Math.max(res, map.get(A[i]).size());
                    //跳到下一次循环
                    continue;
                }
                //获取 当前等差数列中， 理论上的 下1个数的值
                int next = A[j] + diff;
                //记录 等差数列中，最后1个数的下标(初始化为j，即等差数列中第2个数的下标)
                int last_idx = j;
                //HashMap中 存在 当前等差数列， 下1个数的理论值
                while (map.containsKey(next)) {
                    //获取key为理论值的 value(ArrayList)
                    List<Integer> temp_list = map.get(next);
                    //Collections内置函数二分查找
                    last_idx = -(Collections.binarySearch(temp_list, last_idx) + 1);
                    if (last_idx == temp_list.size())
                        break;
                    last_idx = temp_list.get(last_idx);
                    //count + 1
                    ++count;
                    //计算 当前等差数列中， 理论上的 下1个数的值
                    next += diff;
                }
                //更新res的值
                res = Math.max(res, count);
                //count计数 重置为2(从2起步)
                count = 2;
            }
        }
        return res;
    }
}
```