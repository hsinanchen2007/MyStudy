### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        HashSet<String> set = new HashSet<>();
        for(String s:dict) set.add(s);
        String[] res = sentence.split(" ");
        StringBuilder ans = new StringBuilder();
        for(String item:res){
            StringBuilder cur = new StringBuilder();
            boolean suc = true;
            for(char c:item.toCharArray()){
                cur.append(c);
                if(set.contains(cur.toString())){
                    //cur.append(' ');
                    ans.append(cur);
                    ans.append(' ');
                    suc = false;
                    break;
                }
            }
            if(suc){ans.append(cur);ans.append(' ');}
        }
        return ans.toString().substring(0,ans.toString().length()-1);
    }
}
```