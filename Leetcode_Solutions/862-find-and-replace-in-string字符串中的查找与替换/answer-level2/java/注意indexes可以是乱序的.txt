需要先排序indexes
```
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        Map<Integer, String[]> map = new HashMap<>();
        for (int i = 0; i < indexes.length; i++) {
            map.put(indexes[i], new String[] {sources[i], targets[i]});
        }
        List<String> list = new ArrayList<>();
        int start = 0; // 记录当前起始位置
        Arrays.sort(indexes);
        for (int i = 0; i < indexes.length; i++) {
            String source = map.get(indexes[i])[0];
            String target = map.get(indexes[i])[1];
            int index = S.indexOf(source, indexes[i]); // 从indexes[i]查找
            if (index == indexes[i]) { // 必须等于indexed[i]，否则可能在后面的位置找到source
                list.add(S.substring(start, index));
                list.add(target);
                start = index + source.length(); // 更新start位置
            }
        }
        list.add(S.substring(start));
        StringBuilder sb = new StringBuilder(); // 使用StringBuilder更快
        for (int i = 0; i < list.size(); i++) {
            sb.append(list.get(i));
        }
        return sb.toString();
    }
}
```
