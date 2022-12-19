### 执行用时：1ms
balloon共有5个不同的字母，用一个大小为5的数组记录这5个不同字母的出现次数，其中l和o的次数要除以二向下取整（因为一个balloon要包含两个l和两个o）。在这5个不同字母的出现次数中的最小值就是能拼出的balloon的最大数量。

时间复杂度：O(n)。虽然使用了排序，但排序的数组大小永远为5，因此该排序的时间复杂度为常数级别。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] hash = new int[26];
        for(char c : text.toCharArray())
            hash[c - 97]++;
        int[] balloon = new int[5];
        char[] t = "balon".toCharArray();
        for(int i = 0; i < 5; i++)
            balloon[i] = hash[t[i] - 97];
        balloon[2] /= 2;
        balloon[3] /= 2;
        Arrays.sort(balloon);
        return balloon[0];
    }
}
```