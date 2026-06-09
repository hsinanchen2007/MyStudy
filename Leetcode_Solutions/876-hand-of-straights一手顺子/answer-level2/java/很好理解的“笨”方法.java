思路：
1.将数组从小到大排序；
2.在HashMap中存储数字，及出现次数；
3.从数组最小值开始，每次在HashMap中删除W个数（将该值对应的出现次数减一）；
4.寻找下一个HashMap中保存的最小数字（出现次数不为0）作为下次 W循环的开始。

```
class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        //若不能整除直接返回false
        if (hand.length % W != 0)
            return false;
        List<Integer> ls_hand = Arrays.stream(hand).boxed().collect(Collectors.toList());
        Collections.sort(ls_hand, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });

        int min = ls_hand.get(0);
        //键为当前数字，值为该键还剩余多少次可以遍历
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (Integer i : ls_hand) {
            if (hashMap.containsKey(i))
                hashMap.put(i, hashMap.get(i) + 1);
            else
                hashMap.put(i, 1);
        }
        for (int i = 0; i < hand.length; ) {
            boolean flag = true;
            //设置min_tmp是为了不改变min的大小
            for (int j = min; j < min + W; j++) {
                if (hashMap.containsKey(j) && hashMap.get(j) > 0) {
                    hashMap.put(j, hashMap.get(j) - 1);
                    i++;
                } else {
                    return false;
                }
            }
            min = findMinInMap(hashMap);
        }
        return true;
    }

    public int findMinInMap(HashMap<Integer, Integer> map) {
        int min = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getKey() < min && entry.getValue() != 0) {
                min = entry.getKey();
            }
        }
        return min;
    }
}
```
