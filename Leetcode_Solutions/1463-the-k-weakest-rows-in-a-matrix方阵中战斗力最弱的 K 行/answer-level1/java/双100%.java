### 解题思路
![微信图片_20200203143416.png](https://pic.leetcode-cn.com/c3f1151a31e0e2f78d5faf6796c800f0e97a6bc87aa81997a5629a5142487803-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200203143416.png)

mid存的是每行有k（<mat[0].length）个的mat中的行数
然后从0开始一个个读出来，直到返回的数组写满

### 代码

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int []res=new int[k];
        List<List<Integer>> mid=new ArrayList<>();
        for (int i=0;i<=mat[0].length;i++)
            mid.add(new ArrayList<>());
        for (int i=0;i<mat.length;i++){
            for (int j=mat[0].length-2;j>=0;j--){
                mat[i][j]+=mat[i][j+1];
                if (j==0){
                    List<Integer> a=mid.get(mat[i][j]);
                    a.add(i);
                    mid.set(mat[i][j],a);
                }
            }
        }
        int m=0;//返回数组的index
        int i=0;//mid的行
        while (m<k){
            int j=0;//mid每行中的index
            while(j<mid.get(i).size() && m<k){
                res[m++]=mid.get(i).get(j++);
            }
            i++;
        }
        return res;
    }
}
```