1.如果使用递归做，那么必须列举出所有的路径的可能，找到一条能通过的路径，所有路径都不能通过，则失败。
首先定义int[] stones 为石子的位置列表，index表示青蛙在第（index + 1）块石头上，step表示上一步跳跃的单位。
那么青蛙下一步能成功跳到石块公式：
```
Boolean a = Boolean[index + 1, stones.length - 1][step - 1] || Boolean[index + 1, stones.length - 1][step] ||
Boolean[index + 1, stones.length - 1][step + 1]
```
递归边界条件：
```
1. 当index = stones.length - 1时，return true;
2. 当需要跳跃的单位为step，stones[index] + step 在stones{index + 1, stones.length - 1}之间没有值时，return false;
```
代码如下：
```
class Solution {
    public boolean canCross(int[] stones) {
        int index = 0;
        int step = 1;
        return method(stones, index, step);
    }
    public boolean method(int[] stones, int index, int step) {
        for (int i = index + 1; i < stones.length; i++) {
            if(stones[i] == stones[index] + step) {
                index = i;
                break;
            }else if(i == stones.length -1 || stones[i] > stones[index] + step) {
                return false;
            }
        }
        if(index == stones.length - 1) {
            return true;
        }
        boolean b = method(stones, index, step - 1);
        boolean b1 = method(stones, index, step);
        boolean b2 = method(stones, index, step + 1);
        return b || b1 || b2;
    }
}
```
2.是否存在大量重复计算
存在大量计算.....
3.带备忘录的递归
用一个map<String, Booelan> 键：index + "," + step 值：true/false  来表示在第（index + 1）块石头上，上一步跳跃的单位为step，是否成功到达终点。
代码如下：
```
class Solution {
    public boolean canCross(int[] stones) {
        int index = 0;
        int step = 1;
        HashMap<String, Boolean> map = new HashMap<>();
        return method(stones, index, step, map);
    }
    public boolean method(int[] stones, int index, int step, HashMap<String, Boolean> map) {
        for (int i = index + 1; i < stones.length; i++) {
            if(stones[i] == stones[index] + step) {
                index = i;
                if (map.containsKey(index + "," + step)) {
                    return map.get(index + "," + step);
                }
                break;
            }else if(i == stones.length -1 || stones[i] > stones[index] + step) {
                return false;
            }
        }
        if(index == stones.length - 1) {
            return true;
        }
        boolean b = method(stones, index, step - 1, map);
        boolean b1 = method(stones, index, step, map);
        boolean b2 = method(stones, index, step + 1, map);
        boolean b3 = b || b1 || b2;
        map.put(index + "," + step, b3);
        return b3;
    }
}
```
4.动态规划
    4.1 以HashMap<Integer , HashSet<Integer>> map 表示 键：index：当在第（index + 1）块石头上；值：hashset：到达当前石块位置，上一步可以使用的步数step集和。
    4.2 边界条件：当最后一块石头上 没有对应的step集和，说明不能到达最后一块石头，返回false
```
class Solution {
    public boolean canCross(int[] stones) {
        if(stones[1] != 1) {
            return false;
        }
        HashMap<Integer , HashSet<Integer>> map = new HashMap<>();
        HashSet<Integer> set = new HashSet<>();
        set.add(1);
        map.put(1, set);
        for (int i = 1; i < stones.length; i++) {
            if(map.containsKey(i)) {
                HashSet<Integer> hashSet = map.get(i);
                for (Integer step : hashSet) {
                    for (int j = step - 1; j <= step + 1; j++) {
                        for (int x = i + 1; x < stones.length; x++) {
                            if(stones[x] - stones[i] == j) {
                                if (map.containsKey(x)) {
                                    map.get(x).add(j);
                                }else {
                                    HashSet<Integer> set1 = new HashSet<>();
                                    set1.add(j);
                                    map.put(x, set1);
                                }
                                break;
                            }else if(stones[x] - stones[i] > j) {
                                break;
                            }
                        }
                    }
                }
            }else if(i == stones.length -1) {
                return false;
            }
        }
        return true;            
    }
}
```



