### 解题思路
1. 使用回溯算法，进行所有条件探测
2. 注意排序

### 代码

```java
class Solution {
   public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> returnList = new ArrayList<List<Integer>>();

        List<Integer> pritList = Arrays.stream(candidates).boxed().collect(Collectors.<Integer>toList());
        if (candidates.length <= 0 || target <= 0) {
            return returnList;
        }

        return comSum(pritList, target);
    }

    private static List<List<Integer>> comSum(List<Integer> intList, int target) {
        
        List<List<Integer>> retList = new ArrayList<>();
        if (intList.size() <= 0 || target <= 0) {
            return retList;
        }
        List<Integer> copyList = new ArrayList<>(intList);
        int first = copyList.remove(0);
        if (first > target) {
            return comSum(copyList, target);
        } else  {
            int time = target / first;
            for (int i = 0; i < time; i++) {
                List<Integer> list = new ArrayList<>();
                int newTarget = target - (first* (i + 1));
                for (int j = 0; j <= i ; j ++) {
                    list.add(first);
                }
                if (newTarget == 0) {
                    retList.add(list);
                } else {
                    List<List<Integer>> otherList = comSum(copyList, newTarget);
                    if (otherList != null) {
                        for (List<Integer> list1 : otherList) {
                            List<Integer> itemList = new ArrayList<>(list);
                            itemList.addAll(list1);
                            Collections.sort(itemList);
                            retList.add(itemList);
                        }
                    }
                }
            }
            List<List<Integer>> subList = comSum(copyList, target);
            if (subList != null) {
                retList.addAll(subList);
            }
            Collections.sort(retList, new Comparator<List<Integer>>() {
                @Override
                public int compare(List<Integer> o1, List<Integer> o2) {
                    int size = o1.size() > o2.size() ? o2.size() : o1.size();
                    for (int i = 0; i < size; i++) {
                        if (o1.get(i).intValue()  == o2.get(i).intValue()) {
                            continue;
                        }
                        return o1.get(i).intValue() - o2.get(i).intValue();
                    }
                    return o1.size() > o2.size() ? 1: 0;
                }
            });
            return retList;
        }
    }
}
```