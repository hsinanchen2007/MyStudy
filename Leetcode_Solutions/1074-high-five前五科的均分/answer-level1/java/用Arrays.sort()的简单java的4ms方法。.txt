```
class Solution {
    public int[][] highFive(int[][] items) {
        Arrays.sort(items,((a,b) -> ((a[0] == b[0]) ? b[1] - a[1] : a[0] - b[0])));
        int[][] ans = new int[items[items.length-1][0]][2];
        for (int i = 0; i < items.length; i++) {
            if (i == 0 || items[i][0] != items[i-1][0]) {
                ans[items[i][0]-1][0] = items[i][0];
                for (int j = i; j < i+5; j++) ans[items[j][0]-1][1] += items[j][1];
                ans[items[i][0]-1][1] /= 5;          
                i += 4;
            } 
        }
        return ans;
    }
}
```
