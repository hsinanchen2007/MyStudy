### 解题思路
* 蠢笨蠢笨的暴力破解

### 代码

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        Objects.requireNonNull(p);
        assert s.length() <= 20100 && p.length() <= 20100;
        List<Integer> ans = new ArrayList<>();
        char[] target = p.toCharArray();
        Arrays.sort(target);
        char[] src = s.toCharArray();
        int len = src.length - p.length()+1;
        for(int i = 0; i < len; i++) {
            String tmp = s.substring(i,i+target.length);
            char[] cmp = tmp.toCharArray();
            Arrays.sort(cmp);
            if(Arrays.equals(cmp,target)) {
                ans.add(i);
            }
        }
        return ans;
    }
}
```