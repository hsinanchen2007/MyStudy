### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private static final String[] KEYS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public List<String> letterCombinations(String digits) {
        List<String> ret = new ArrayList<>();
        if(digits.length() == 0){
            return ret;
        }
        // 取出第一个字符
        char first = digits.charAt(0);
        int index = first - '0';
        // 第一个数字所对应的字符串
        String chars = KEYS[index];
        List<String> list = letterCombinations(digits.substring(1));
        if(list.size() == 0){
            for(char head : chars.toCharArray()){
                ret.add(String.valueOf(head));
            }
        }
        else{
            StringBuffer sb = new StringBuffer();
            for(char head : chars.toCharArray()){
                sb.append(head);
                for(String str : list){
                    sb.append(str);
                    ret.add(sb.toString());
                    sb.delete(1, sb.length());
                }
                sb.deleteCharAt(0);

            }
            
        }
        return ret;
    }
}
```