### 解题思路
做了优化就不超时了

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int num = target / 2 + 1;
        int length = 0;
        ArrayList<int[]> reslist = new ArrayList<>();
        for (int i = 1; i < num; i++)
            for (int j = i + 1; j <= num; j++) {
                int sum = (i + j) * (j - i + 1);
                if (sum == target * 2) {
                    int[] ints = new int[j - i + 1];
                    length++;
                    for (int k = 0; k < j - i + 1; k++)
                        ints[k] = i + k;
                    reslist.add(ints);
                }else if(sum > target * 2)//在此处做了优化就不超时了
                    break;
            }
        int[][] res = new int[length][];
        for (int i = 0; i < length; i++)
            res[i] = reslist.get(i);
        return res;
    }
}
```