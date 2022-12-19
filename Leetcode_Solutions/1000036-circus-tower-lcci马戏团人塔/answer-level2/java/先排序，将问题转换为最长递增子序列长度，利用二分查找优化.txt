### 解题思路
1.将height进行插入排序，height[i]==height[j],按weight排序
（【更新】题目要求中“上面的人要比下面的人矮一点且轻一点”，所以身高相同时，不能同时参与叠罗汉。height[i]==height[j],按weight降序排序，比如[1,1],[1,2]排序后变成了[1,1][2,1],那么[2,1]的最长递增子序列长度为1）。
2.找出排序之后的weight的最长递增子序列长度。
ends[i]=w,表示所有长度为i+1的递增子序列中，最小的结尾数是w。利用二分法找到在ends中最左边大于或等于weight[j]的数

### 代码

```java
class Solution {
    public int bestSeqAtIndex(int[] height, int[] weight) {
        if (height == null || height.length == 0 || weight == null || weight.length == 0 || height.length != weight.length) {
            return 0;
        }
        if (height.length == 1) {
            return 1;
        }
        int n = height.length;
        int ans = 0;
        insertSort(height, weight);
        int[] ends = new int[n];
        int l = 0,r=0,m=0,right=0;
        ends[0]=weight[0];
        for (int i = 1; i < n; i++) {
            l = 0;
            r=right;
            while (l<=r) {
                m = (l+r)/2;
                if (weight[i] > ends[m]) {
                    l = m+1;
                } else {
                    r=m-1;
                }
            }
            ends[l] = weight[i];
            right = Math.max(right,l);
            ans = Math.max(ans, l+1);
        }
        return ans;
    }

    private void insertSort(int[] height, int[] weight) {
        int n = height.length;
        for (int i = 1; i < n; i++) {
            int cur = height[i];
            int curWeight = weight[i];
            int j = i-1;
            while (j >= 0 && (height[j] > cur || height[j] == cur && weight[j] < curWeight)) {
                height[j+1] = height[j];
                weight[j+1] = weight[j];
                j--;
            }
            height[j+1] = cur;
            weight[j+1] = curWeight;

        }
    }
}
```