用i表示符合要求的长度，
那么数组长度就是以target/i为中心向左右扩散，
左右分别i/2，但是如果是i是偶数的情况下，我们占用了一个左边的位置，
那么左边就剩下(i-1)/2 我们惊喜的发现，即使i是是奇数，左边的数值，也满足条件
求出左边界和右边界，如果出界就跳出（我感觉跳出条件可以优化，但是想不出来了）

```
class Solution {
    public int[][] findContinuousSequence(int target) {
        List <int []> res = new ArrayList<>();
        for(int i=2;i<target/2+1;i++){
            int l=target/i-(i-1)/2;
            int r=target/i+i/2;
            if(l<1 || r> target)break;
            if((l+r)*(r-l+1)/2==target){
                int [] s=new int[r-l+1];
                for(int k=0;k<i;k++)s[k]=k+l;
                res.add(s);
            }
        }
        Collections.reverse(res);
        return res.toArray(new int[res.size()][]);
    }
}
```
