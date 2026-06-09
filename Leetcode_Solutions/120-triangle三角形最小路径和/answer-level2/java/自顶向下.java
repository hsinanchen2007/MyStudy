自顶向下，从左至右遍历需要保存上一层数据。


```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int m = triangle.size(); 
        if(m<1)
            return 0;
        if(m==1)
            return triangle.get(0).get(0);
        int n = triangle.get(m-1).size(); 
        int[] a = new int[n];
        int[] pre = new int[]{triangle.get(0).get(0)};
        int min = Integer.MAX_VALUE;
        for(int i = 1; i<m; i++){
            for(int j = 0; j<triangle.get(i).size(); j++){
                if(j==0)
                    a[j] = pre[j]+triangle.get(i).get(j);
                else if(j==triangle.get(i).size()-1)
                    a[j] = pre[j-1]+triangle.get(i).get(j);
                else
                    a[j] = Math.min(pre[j-1],pre[j])+triangle.get(i).get(j);
                if(i==m-1)
                    min = Math.min(a[j],min);
            }
            pre=a.clone();
        }
        return min;
    }
}
```
