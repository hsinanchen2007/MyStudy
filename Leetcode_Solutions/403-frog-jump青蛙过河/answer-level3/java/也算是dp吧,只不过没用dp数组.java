### 解题思路
用一个map记录前面的结果,然后遍历.这个也算是dp吧,只不过没用dp数组..

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class Solution {
    public static void main(String[] args) {
        int[] stones = {0, 1, 3, 5, 6, 8, 12, 17};
        boolean b = canCross(stones);
        System.out.println("b = " + b);

    }
    public static boolean canCross(int[] stones) {
        if (stones[1]-stones[0]!=1) return false;
        /**
         * 不是dp数组,就是把前面走过的结果保存在hashset里面,然后遍历,
         * 其实也算是dp了,记录下之前的结果到set里面,然后尝试.
         *
         * */
        HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
        HashSet<Integer> list1 = new HashSet<>();
        list1.add(1);
        map.put(1, list1);
        for (int i = 1; i < stones.length; i++) {
            HashSet<Integer> list2 = map.get(i);
            if (list2 == null || list2.size() == 0) {
                continue;
            }
            for (int distance : list2) {
                int i1 = Arrays.binarySearch(stones, stones[i] + distance);
                int i2 = -1;
                if (distance > 1) {
                    i2 = Arrays.binarySearch(stones, stones[i] + distance - 1);
                }
                int i3 = Arrays.binarySearch(stones, stones[i] + distance + 1);
                if (i1 > 0) {
                    if (map.containsKey(i1)) {
                        HashSet<Integer> list3 = map.get(i1);
                        list3.add(distance);
                        map.put(i1, list3);
                    } else {
                        HashSet<Integer> list = new HashSet<>();
                        list.add(distance);
                        map.put(i1, list);
                    }
                }
                if (i2 > 0) {
                    if (map.containsKey(i2)) {
                        HashSet<Integer> list3 = map.get(i2);
                        list3.add(distance - 1);
                        map.put(i2, list3);
                    } else {
                        HashSet<Integer> list = new HashSet<>();
                        list.add(distance - 1);
                        map.put(i2, list);
                    }
                }
                if (i3 > 0) {
                    if (map.containsKey(i3)) {
                        HashSet<Integer> list3 = map.get(i3);
                        list3.add(distance + 1);
                        map.put(i3, list3);
                    } else {
                        HashSet<Integer> list = new HashSet<>();
                        list.add(distance + 1);
                        map.put(i3, list);
                    }
                }
            }
        }
        return map.containsKey(stones.length - 1);
    }
}

```