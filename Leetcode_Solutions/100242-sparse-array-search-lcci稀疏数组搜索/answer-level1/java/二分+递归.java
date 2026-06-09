### 解题思路
用一个二维数组辅助

### 代码

```java
class Solution {
    public int findString(String[] words, String s) {
        //二维数组，一维存索引，二维存字符串长度
        int[][] lens = new int[words.length][2];
        for(int i = 0; i < words.length; i++) {
            lens[i][0] = i;
            lens[i][1] = words[i].length();
        }
        //排序
        Arrays.sort(lens, (i1, i2) -> i1[1] - i2[1]);
        return helper(words, lens, 0,  words.length - 1, s);
    }
    
    public int helper(String[] words, int[][] lens, int left, int right, String s) {
        while(left <= right) {
            int mid = (left + right) / 2;
            //长度相等
            if(lens[mid][1] == s.length()) {
                if(words[lens[mid][0]].equals(s)) {
                    return lens[mid][0];
                }
                //左边
                int tl = helper(words, lens, left, mid - 1, s);
                if(tl != -1) return tl;
                //右边
                int tr = helper(words, lens, mid + 1, right, s);
                if(tr != -1) return tr;
                return -1;
            } else if(lens[mid][1] > s.length()) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(lens[left - 1][1] == s.length()) {
            if(words[lens[left - 1][0]].equals(s)) {
                return lens[left - 1][0];
            }
        }
        return -1;
    }
}
```