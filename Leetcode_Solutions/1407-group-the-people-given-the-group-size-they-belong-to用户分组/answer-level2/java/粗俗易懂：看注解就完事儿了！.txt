```
class Solution {
    // 针对方式一的小优化
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> result = new ArrayList<>();
        int len = groupSizes.length;
        if (len < 1) return result;

        Map<Integer, List<Integer>> record = new HashMap<>();
        for (int i = 0; i < len; i++){
            int curGroupNum = groupSizes[i];
            List<Integer> curGroup = record.get(curGroupNum);
            if (curGroup == null){ // 如果当前组还没在map中记录，则进行新建
                curGroup = new ArrayList<>();
            }
            curGroup.add(i); // 添加当前组的员工
            if (curGroup.size() == curGroupNum){// 到达最后一个了，则添加之后把当前组加入到结果集中，并且删掉这个组
                result.add(curGroup);
                curGroup = null;
            }
            record.put(curGroupNum, curGroup);
        }

        return result;
    }

    /*public List<List<Integer>> groupThePeople1(int[] groupSizes) {
        List<List<Integer>> result = new ArrayList<>();
        int len = groupSizes.length;
        if (len < 1) return result;

        Map<Integer, List<Integer>> record = new HashMap<>();
        for (int i = 0; i < len; i++){
            int curGroupNum = groupSizes[i];
            List<Integer> curGroup = record.get(curGroupNum);
            if (curGroup == null){ // 如果当前组还没在map中记录，则进行新建
                List<Integer> newGroup = new ArrayList<>();
                newGroup.add(i); // 添加当前组的员工
                record.put(curGroupNum, newGroup);
            }else{ // 如果存在了当前组
                if (curGroup.size() < curGroupNum){ // 当前组的人数小于组号
                    curGroup.add(i);
                }else{ // 当前组满了
                    result.add(curGroup);
                    List<Integer> newGroup = new ArrayList<>();
                    newGroup.add(i); // 添加当前组的员工
                    record.put(curGroupNum, newGroup);
                }
            }
        }

        for (List<Integer> list : record.values()){ // 将记录全部加入到结果集中
            result.add(list);
        }

        return result;
    }*/
}
```
