思路：递推，从一个元素开始，到n个元素为止，递推出所有满足条件的排列组合，其中n是字模tiles的长度。
<br/><br/>
以"AAB"举例：
1. 选一个元素的情况：有：["A","B"]，二者都满足条件。
2. 选两个元素的情况：在选一个元素的情况下，叠加一次选一个元素，即为选两个元素的情况。有：["AA","AB","BA","BB"]，四种，其中满足条件的只有：["AA","AB","BA"]。
3. 选三个元素的情况：在选两个元素的情况下，叠加一次选一个元素，即为选三个元素的情况。有：["AAA","ABA","BAA","AAB","ABB","BAB"]，六种，其中满足条件的只有：["ABA","BAA","AAB"]。

代码：
```
class Solution {
    public int numTilePossibilities(String tiles) {
        Map<Integer,Set<String>> map = new HashMap<>();
        Set<String> base = new HashSet<>();
        
        for (int i = 0;i < tiles.length();i++) {
            base.add(String.valueOf(tiles.charAt(i)));
        }
        
        map.put(1,base);
        
        for (int i = 2;i <= tiles.length();i++) {
            Set<String> last = map.get(i - 1);
            Set<String> cur = new HashSet<>();
            
            for (String l : last) {
                for (String b : base) {
                    String add = new String(l + b);
                    if (judge(add,tiles)) {
                        cur.add(add);
                    }
                }
            }
            
            map.put(i,cur);
        }
        
        // System.out.println(map);
        
        int ans = 0;
        
        for (int i = 1;i <= tiles.length();i++) {
            ans += map.get(i).size();
        }
        
        return ans;
    }
    
    private boolean judge(String s,String r) {
        int sa[] = new int[26];
        for (int i = 0;i < s.length();i++) {
            sa[s.charAt(i) - 'A']++;
        }
        int ra[] = new int[26];
        for (int i = 0;i < r.length();i++) {
            ra[r.charAt(i) - 'A']++;
        }
        
        for (int i = 0;i < sa.length;i++) {
            if (sa[i] > ra[i]) {
                return false;// 排列组合后的结果中的字符不能超过原有字模中的字符
            }
        }
        
        return true;
    }
}
```
