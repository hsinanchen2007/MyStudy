根据题意，这个返回结果其实是满足这个条件的：
- 它是包含在s里的，比如`ab***lea`和`apple`。
- 如果有多个符合的，则返回最长的。
- 如果最长的不止一个，则返回字典顺序最小的。例如`abc`和`abd`，就会返回`abc`。

🧐因此我的代码如下，有点啰嗦，一遍过的，没去看怎么修改和优化，仅仅是提供一个思路：
```java
class Solution {
    public String findLongestWord(String s, List<String> d) {
        String result = "";
        int maxLength = 0;
        //挨个判断d中的每个str是否包含在s中
        //如果包含，则用result来记录最长&字典顺序最小的字符串，用maxLength来记录当前最大长度
        for(String str : d){
            int p1 = 0, p2 = 0, len = 0;
            while(p1 < s.length() && p2 < str.length()){
                while(p1 < s.length() && s.charAt(p1) != str.charAt(p2)){
                    p1++;
                }
                if(p1 >= s.length()){
                    break;
                }
                //完成s和str的一个字符的匹配
                len++;
                p2++;
                p1++;
            }
            //当p2 == str.length()时，说明str中每一个字母都包含在s里了，这个str是满足题目的条件。
            if(p2 == str.length()){
                //str和当前最长的字符串一样长时，则将字典顺序小的更新为result
                if(len == maxLength){
                    if(str.compareTo(result) < 0){
                        result = str;
                    }
                }
                //str比当前最长的字符串长时，将str更新为result，同时更新maxLength
                if(len > maxLength){
                    maxLength = len;
                    result = str;
                }
            }
        }
        return result;
    }
}
```
