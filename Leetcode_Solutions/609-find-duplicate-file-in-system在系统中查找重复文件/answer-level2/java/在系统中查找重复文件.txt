#### 方法一：哈希表

首先我们通过字符串操作获取目录路径、文件名和文件内容。我们使用哈希映射（HashMap）来寻找重复文件，哈希映射中的键（key）是文件内容，值（value）是存储路径和文件名的列表。

我们遍历每一个文件，并把它加入哈希映射中。在这之后，我们遍历哈希映射，如果一个键对应的值列表的长度大于 `1`，说明我们找到了重复文件，可以把这个列表加入到答案中。

<![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/609/Find_Duplicate_Files_HashmapSlide8.PNG)>


```Java [sol1]
public class Solution {
    public List < List < String >> findDuplicate(String[] paths) {
        HashMap < String, List < String >> map = new HashMap < > ();
        for (String path: paths) {
            String[] values = path.split(" ");
            for (int i = 1; i < values.length; i++) {
                String[] name_cont = values[i].split("\\(");
                name_cont[1] = name_cont[1].replace(")", "");
                List < String > list = map.getOrDefault(name_cont[1], new ArrayList < String > ());
                list.add(values[0] + "/" + name_cont[0]);
                map.put(name_cont[1], list);
            }
        }
        List < List < String >> res = new ArrayList < > ();
        for (String key: map.keySet()) {
            if (map.get(key).size() > 1)
                res.add(map.get(key));
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是文件的总数。这里认为每个文件名的长度是常数级别的。

* 空间复杂度：$O(N)$。