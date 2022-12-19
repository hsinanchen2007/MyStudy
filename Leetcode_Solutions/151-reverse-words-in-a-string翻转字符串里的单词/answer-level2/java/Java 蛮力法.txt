### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        List<String> list = new ArrayList<>();
        for(String sub : s.split(" ")){
            if("".equals(sub)) continue;
            list.add(sub.trim());
        }
        for(int i = list.size() -1 ; i >=0;i--){
            sb.append(list.get(i)).append(" ");
        }
        return sb.toString().trim();
    }
}
```