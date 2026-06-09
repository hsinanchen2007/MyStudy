### 解题思路
排序后，如果当前文件夹路径包含之前的路径则跳过，不包含放入结果列表

### 代码

```java
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        List<String> result = new LinkedList<>();
        Arrays.sort(folder);
        String pre = " ";
        for (String directory : folder) {
            int index = directory.indexOf(pre);
            int end = index + pre.length();
            if (index == -1 || (end < directory.length() && directory.charAt(end) != '/')) {
                result.add(directory);
                pre = directory;
            }
        }
        return result;
    }
}
```