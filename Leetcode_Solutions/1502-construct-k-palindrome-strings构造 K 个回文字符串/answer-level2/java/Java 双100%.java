核心：记录多少个 奇数个数字符，总数 <= k则必然成立

```
    class Solution {
        public boolean canConstruct(String s, int k) {
            if(s.length()<k)return false;
            int c[]=new int[26];
            for(char cc:s.toCharArray())
                c[cc-'a']++;
            int odd=0;
            for(int i=0;i<26;i++)
                if((c[i]&1)==1)odd++;
            return !(odd>k);
        }
    }
```
