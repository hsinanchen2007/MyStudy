### 解题思路
[Leetcode076](https://leetcode-cn.com/problems/minimum-window-substring/)
[滑动窗口模板](https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/)

### 代码

```java
class Solution {
    public int[] shortestSeq(int[] big, int[] small) {
        if(big.length < small.length) return new int[0];
        Map<Integer, Integer> smallMap = new HashMap<>(small.length);
        for (int i = 0; i < small.length; i++) {
            smallMap.put(small[i], smallMap.getOrDefault(small[i], 0) +1);
        }
        Map<Integer, Integer> bigMap = new HashMap<>(small.length);
        int left = 0, right = 0, match = 0;
        int min = Integer.MAX_VALUE;
        int l = -1, r = -1;
        while(right < big.length){
            int rightValue = big[right++];
            if(smallMap.containsKey(rightValue)){
                bigMap.put(rightValue, bigMap.getOrDefault(rightValue, 0) +1);
                if(smallMap.get(rightValue).equals(bigMap.get(rightValue))){
                    match++;
                }
            }
            while(match == smallMap.size()){
                if(right - left < min){
                    l =  left;
                    r = right;
                    min = right - left;
                }
                int leftValue = big[left++];
                if(smallMap.containsKey(leftValue)){
                    bigMap.put(leftValue, bigMap.get(leftValue)-1);
                    if(bigMap.get(leftValue) < smallMap.get(leftValue)) {
                        match--;
                    }
                }
            }
        }
        if(r-1 < l ) {
            return new int[0];
        } else {
            return new int[]{l,r-1};
        }
    }
}
```