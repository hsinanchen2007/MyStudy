使用JAVA的TreeMap直接构建最终的关键点集合，key代表红坐标，value代表纵坐标。
先处理building（b）的右边线r，若r左边没有放高度为0的射线，若有但比b高度低的，放高度为r左边高度的射线，否则不管。
再处理b的左边线l，若l左边没有或l左边的比b矮，则在此放高度为b高度的射线，否则不管。
然后处理b左右边线中间的节点，若是节点的高度低于b的高度，则将之提高至b的高度。
最后一次将treeMap里点依次当如列表，与之前一个点高度相同的跳过不放。
JAVA实现如下：
```
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        if(buildings == null ||buildings.length == 0){
            return new ArrayList<>();
        }
        TreeMap<Integer, Integer> coll = new TreeMap<>();
        Map.Entry<Integer, Integer> temp1;
        for (int[] ints : buildings) {
            //先处理右下角问题
            temp1 = coll.floorEntry(ints[1]);
            if (temp1 == null){
                coll.put(ints[1], 0);
            }
            else if(temp1.getValue() < ints[2]){
                coll.put(ints[1], temp1.getValue());
            }
            //再处理左上角问题
            temp1 = coll.floorEntry(ints[0]);
            if(temp1 == null || temp1.getValue() < ints[2]){
                coll.put(ints[0], ints[2]);
            }
            //最后处理中间的点。
            for (Map.Entry<Integer, Integer> entry : coll.subMap(ints[0], ints[1]).entrySet()) {
                if(entry.getValue() < ints[2]){
                    entry.setValue(ints[2]);
                }
            }
        }
        ArrayList<List<Integer>> ans = new ArrayList<List<Integer>>(){{
            add(new ArrayList<Integer>(){{
                add(coll.firstEntry().getKey());
                add(coll.firstEntry().getValue());
            }});
        }};
        for (Map.Entry<Integer, Integer> entry : coll.entrySet()) {
            if (ans.get(ans.size() - 1).get(1).equals(entry.getValue())){
                continue;
            }
            ans.add(new ArrayList<Integer>(){{
                add(entry.getKey());
                add(entry.getValue());
            }});
        }
        return ans;
    }
}
```
