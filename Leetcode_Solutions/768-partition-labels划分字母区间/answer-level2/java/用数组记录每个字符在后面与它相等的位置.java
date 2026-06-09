### 解题思路
用一个数组记录每个字母后面是否有与之相等的字母
有的话就存入这个字母后面中最后与之相等字母的位置，没有就为-1

### 代码

```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> res = new ArrayList<>();
        if (S == null || S.length() == 0) {
            return res;
        }
        int[] pos = new int[S.length()];
        for (int i = S.length() - 1; i >= 0; i--) {
            int nextPos = -1;
            for (int j = S.length() - 1; j >= i + 1; j--) {
                if (S.charAt(j) == S.charAt(i)) {
                    nextPos = j;
                    break;
                }
            }
            pos[i] = nextPos;
        }
        int start = 0;
        while (start < S.length()) {
            int index = start;//每个字符串片段起始位置
            int end = pos[start];//每个字符串片段结束位置
            if (end == -1) {//只有一个字符时直接加入
                res.add(1);
            } else {
                while (start < end) {//有多个字符
                    start++;
                    end = Math.max(pos[start], end);//尽可能往后延长每个字符串片段的结束位置，直到该字符串片段的每个字符往后
                                                    //找都没有与他相等的字符
                }
                int len = end - index + 1;
                res.add(len);
            }
            start++;
        }
        return res;
    }
}
```