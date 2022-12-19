执行用时 :
234 ms, 在所有 java 提交中击败了6.00%的用户
内存消耗 :
53.3 MB
, 在所有 java 提交中击败了82.76%的用户
### 解题思路


1.我这写的比较乱
2.先找到所有的文件和文件内容
3.然后用map进行存储，找到大于等于2的大小的列表
4.返回

### 代码

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
class MyFile{
        String path;
        String fileName;
        String content;

        @Override
        public String toString() {
            return "MyFile{" +
                    "path='" + path + '\'' +
                    ", fileName='" + fileName + '\'' +
                    ", content='" + content + '\'' +
                    '}';
        }

        public MyFile(String path, String fileName, String content) {
            this.path = path;
            this.fileName = fileName;
            this.content = content;
        }
    }

    public List<List<String>> findDuplicate(String[] paths) {
        List<List<String>> ansList = new ArrayList<>();
        Map<String, List<String>> duplicateMap = new HashMap<>();
        List<MyFile> tempList = new ArrayList<>();
        String reg = "(\\([^\\)]*\\))";
        Pattern pattern = Pattern.compile(reg);
        for (String s:paths){
            String[] split = s.split(" ");
            int len = split.length;
            String path = split[0];
            for (int i = 1; i < len; i++) {
                Matcher matcher = pattern.matcher(split[i]);
                if (matcher.find()){
                    String content = matcher.group();
                    StringBuffer sp = new StringBuffer(split[i]);
                    StringBuffer filename = sp.replace(matcher.start(),matcher.end(),"");
                    MyFile myFile = new MyFile(path, filename.toString(), content);
                    System.out.println(myFile);
                    tempList.add(myFile);
                }
            }
        }
        for (MyFile myFile:tempList){
            if (duplicateMap.containsKey(myFile.content)){
                List<String> strings = duplicateMap.get(myFile.content);
                strings.add(myFile.path+"/"+myFile.fileName);
                duplicateMap.put(myFile.content,strings);
            }else {
                List<String> strings = new ArrayList<>();
                strings.add(myFile.path+"/"+myFile.fileName);
                duplicateMap.put(myFile.content,strings);
            }
        }
      for (String content:duplicateMap.keySet()){
            List<String> strings = duplicateMap.get(content);
            if (strings.size()>=2){
                ansList.add(strings);
            }
        }

        return ansList;
    }
}
```