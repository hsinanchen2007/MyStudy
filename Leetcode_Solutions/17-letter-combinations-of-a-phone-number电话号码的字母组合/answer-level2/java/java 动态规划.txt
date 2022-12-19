### 解题思路
假设我们有一个dp数组，索引为i处的值表示当前位置的字符串列表
      那么dp[i+1] = dp[i]的每一项添加i+1处代表的数组每一个char
      for(String s:dp[i]){
            for(char i : chars[i+1]){
                String newStr = s+i;
                dp[i+1].add(newStr);
            }
     }

注意到dp数组的每一项代表了一个List<String>
     所以这里最好用List<List<String>>来表示dp
 
### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
            char[][] digitChars = new char[][]{
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m','n','o'},
                {'p','q','r','s'},
                {'t','u','v'},
                {'w','x','y','z'}
      };
        if(digits==null||digits.length()==0){
            return Collections.emptyList();
        }
        List<List<String>> dpList = new ArrayList<>();
        int length = digits.length();
        int lastIndex = length-1;
        char[] digitChar0 = digitChars[digits.charAt(0)-'2'];
        List<String> dp0List = new ArrayList<>();
        for(char i :digitChar0){
            dp0List.add(String.valueOf(i));
        }
        dpList.add(dp0List);
        for(int i = 1;i<=lastIndex;i++){
            List<String> dp_i_1_list = dpList.get(i-1);
            char[] currentChars = digitChars[digits.charAt(i)-'2'];
            List<String> dp_i_list = new ArrayList<>();
            for(String str:dp_i_1_list){
                for(char charI : currentChars){
                    String newStr = str+charI;
                    dp_i_list.add(newStr);
                }
            }
            dpList.add(dp_i_list);
        }

        return dpList.get(lastIndex);
    }
}
```