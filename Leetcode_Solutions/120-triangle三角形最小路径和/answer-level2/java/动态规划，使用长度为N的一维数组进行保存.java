数组中p[]中第i个元素表示每次当前层中以第i个节点为终止节点的最小路径。
```java []
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size() == 0) return 0;
        if(triangle.size() == 1) return triangle.get(0).get(0);
        int N = triangle.size();
        int[] p = new int[N];
        p[0] = triangle.get(0).get(0);
        for(int i = 1; i < N; i++){
            for(int j = i; j>=0; j--){
                if(j == i) p[j] = p[j-1] + triangle.get(i).get(j);
                else if(j == 0) p[0] = p[0] + triangle.get(i).get(0);
                else p[j] = Math.min(p[j], p[j-1]) + triangle.get(i).get(j);
            }
        }
        int ans =p[0];
        for(int k = 1; k < N; k++){
            ans = Math.min(ans, p[k]);
        }
        return ans;
    }
}
```

