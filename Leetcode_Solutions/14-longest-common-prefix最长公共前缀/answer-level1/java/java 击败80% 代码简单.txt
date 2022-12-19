### 解题思路
此处撰写解题思路
时间复杂度 nlongn
代码还是挺简单的
思路 先排序，这样就可以比较第一和最后一个
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";
        StringBuilder res = new StringBuilder();
        Arrays.sort(strs);
        String first = strs[0];
        String last = strs[strs.length-1];
        for(int i=0; i< first.length();i++){
            if(first.charAt(i) == last.charAt(i)){
                res.append(first.charAt(i));
            }
            else{
                return res.toString();
            }
        }
        return res.toString();
    }
}
```