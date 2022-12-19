### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1 == null || s1.length() == 0 || s2 == null || s2.length() == 0) {
            return false;
        }
        int[] windows = new int[128];
        int[] needs = new int[128];
        for (char c : s1.toCharArray()) {
            needs[c]++;
        }

        int left = 0;
        int right = 0;
        int match = 0;

        while(right < s2.length()){
            char r = s2.charAt(right);
            if (needs[r] > 0) {
                windows[r]++;
                if (needs[r] >= windows[r]) {
                    match++;
                }
            }
            right++;

            while(match == s1.length()){
                char l = s2.charAt(left);
                if(needs[l] > 0){
                    windows[l]--;
                    if (needs[l] > windows[l]) {
                        match--;
                    }
                }
                
                //这里需要和76和438区分
                if(matches(windows,needs) && (right-left == s1.length())){
                    return true;
                }

                left++;
            }
        }
        return false;
    }
    public boolean matches(int[] s1map, int[] s2map) {
        for (int i = 0; i < 26; i++) {
            if (s1map[i] != s2map[i])
                return false;
        }
        return true;
    }
}
```