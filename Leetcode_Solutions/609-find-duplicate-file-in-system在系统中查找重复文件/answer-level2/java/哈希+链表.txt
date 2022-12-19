```
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String,List<String>> map = new HashMap<>();
        List<List<String>> result = new LinkedList<>();
        for(int i = 0;i<paths.length;i++){
            String[] path = paths[i].split(" ");
            for(int j = 1;j<path.length;j++){
                String[] temp = path[j].split("\\(");
                temp[1] = temp[1].replace(")","");
                List<String> pathList = map.getOrDefault(temp[1],new LinkedList<String>());
                pathList.add(path[0]+"/"+temp[0]);
                map.put(temp[1],pathList);
            }
        }
        for(Map.Entry<String,List<String>> e : map.entrySet()){
            if(e.getValue().size()>1){
                result.add(e.getValue());
            }
        }
        return result;
    }
}
```
思路：
    1.将所有的文件路径遍历存入hashmap钟，key值为（）中的文件内容，value值为list，list中存放所有文件内       容相同的文件的路径
    2.遍历map，找多所有value值中的list长度大于1的kv对，把value中的链表取出来存到结果集链表中
