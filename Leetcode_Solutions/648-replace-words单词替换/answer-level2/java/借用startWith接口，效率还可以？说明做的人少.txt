### 解题思路
借用startWith接口，效率还可以？说明做的人少，下面尝试效率更高的算法

### 代码

```java
class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        String[] words = sentence.split(" ");
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            boolean isFind = false;
            for (int j = 0; j < dict.size(); j++) {
                if (word.startsWith(dict.get(j))) {
                    isFind = true;
                    stringBuffer.append(dict.get(j) + " ");
                    break;
                }
            }
            if (!isFind) {
                stringBuffer.append(word + " ");
            }
        }
        return stringBuffer.substring(0, stringBuffer.length() - 1);
    }
}
```