### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
       public List<Integer> findAnagrams(String s, String p) {

        List<Integer> list = new ArrayList<>();
        int[] freq = new int[256];
        Arrays.fill(freq,0);

        char[] cs = s.toCharArray();
        char[] cp = p.toCharArray();

        for (char num:cp) {
            freq[num]++;
        }

        int l=0,r =-1;
        while (l < cs.length){
            if ( r+1< cs.length && freq[cs[r+1]] != 0){
                freq[cs[r+1]]--;
                r++;
            }else {
                freq[cs[l]]++;
                l++;
            }
            if (r-l+1 == cp.length)
                  list.add(l);
        }

        return list;
       }
    }
```