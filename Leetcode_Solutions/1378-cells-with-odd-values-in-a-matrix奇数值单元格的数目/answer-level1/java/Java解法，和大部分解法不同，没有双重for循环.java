主要思想是先按行再按列统计奇数的个数，最后对于重合点进行去重
```
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int[] r=new int[n];
        int[] c=new int[m];
        // 按行和列分别记录出现的次数
        for (int i=0;i<indices.length;i++) {
            r[indices[i][0]]++;
            c[indices[i][1]]++;
        }
        int sum=0,count=0;
        // 先按行统计奇数的个数,并记录奇数出现的次数以便进行去除(行奇数和列奇数的重合点必然是偶数)
        for (int i=0;i<n;i++) {
            if ((r[i]&1)==1) {
                sum+=m;
                count++;
            }
        }
        // 再按列统计奇数的个数,将重合点去除
        for (int i=0;i<m;i++) {
            if ((c[i]&1)==1) {
                sum=sum-2*count+n;
            }
        }
        
        return sum;
    }
}
```
