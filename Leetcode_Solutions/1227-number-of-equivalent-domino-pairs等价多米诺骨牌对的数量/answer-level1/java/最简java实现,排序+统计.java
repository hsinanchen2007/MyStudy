

遍历，先排序，消除等价骨牌差异性，然后每多一个A骨牌的等价骨牌，给当前对数 贡献了目前A骨牌的个数；

时间90%+， 内存100%；

```
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int ans = 0;
        int[] cp = new int[100];
        for(int[] arr:dominoes){
            Arrays.sort(arr);
            ans+=cp[arr[0]*10+arr[1]]++;
        }
        return ans;
    }
}
```