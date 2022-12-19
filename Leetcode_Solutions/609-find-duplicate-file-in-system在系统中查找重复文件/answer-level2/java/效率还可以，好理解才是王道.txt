### 解题思路
这里的重点是利用indexOf获得要截取字符串的位置
另外一个要看清题目，是输出重复的文件，不重复的不算


### 代码

```java
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        HashMap<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < paths.length; i++) {
            String[] strings = paths[i].split(" ");
            String path = strings[0];
            for (int j = 1; j < strings.length; j++) {
                String file = strings[j];
                //获取content
                String content = file.substring(file.indexOf("(") + 1);
                //去掉最后一个)
                String contentReal = content.substring(0, content.length() - 1);
                //拼接路径
                String string = path + "/" + file.substring(0, file.indexOf("("));
                if (map.containsKey(contentReal)) {
                    map.get(contentReal).add(string);
                } else {
                    List<String> arrayList = new ArrayList();
                    arrayList.add(string);
                    map.put(contentReal, arrayList);
                }
            }
        }
        List<List<String>> results = new ArrayList<>();
        for (Map.Entry entry : map.entrySet()) {
            //注意题目是获取重复的文件，不重复的不算
            if (((List<String>) entry.getValue()).size() < 2) {
                continue;
            }
            results.add((List<String>) entry.getValue());
        }
        return results;
    }
}
```