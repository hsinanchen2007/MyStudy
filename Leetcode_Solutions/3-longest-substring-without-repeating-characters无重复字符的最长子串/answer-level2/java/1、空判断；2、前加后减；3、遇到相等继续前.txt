### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if("".equals(s)){
            return 0;
        }
                            String[] strs = s.split("");
        int length = strs.length;
        int i=0,j=0;
        Set<String> set = new HashSet();
        int max =0;

        while(i<= j && j < length){
            String strj = strs[j];
            if(!set.contains(strj)){
                set.add(strj);
                j++;
                if(set.size() > max){
                    max = set.size();
                }
            }else{
                String stri = strs[i];
                set.remove(stri);
                i++;
                if (stri == strj) {
                    j++;
                }
            }
        }
        return max;

    }
}
```