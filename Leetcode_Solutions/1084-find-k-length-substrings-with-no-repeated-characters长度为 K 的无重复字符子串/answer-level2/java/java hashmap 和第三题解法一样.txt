1. 用一个hashmap存储字符和字符所在的位置

2. 然后在[i,j)区间里，如果找到在map里存在的字符，就更新到这个字符的上一个位置+1

3. 当区间长度为K时，结果+1 同时i也要向右挪

4. 最后存入新的字符和它所在的位置到map里


时间复杂度是O(n) 空间复杂度是O(26)

```
class Solution {
    public int numKLenSubstrNoRepeats(String S, int K) {
        HashMap<Character, Integer> map = new HashMap<>();//存的是char和它所在的位置
        int res = 0;
        int i = 0;
        for(int j = 0; j < S.length(); j++)
        {
            if(map.containsKey(S.charAt(j)))
                i = Math.max(map.get(S.charAt(j)) + 1, i);
            if(j - i == K - 1)
            {
                res++;
                i++;
            }
            map.put(S.charAt(j), j);
        }
        return res;
    }
}
```
