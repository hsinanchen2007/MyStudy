先排序
使用两层循环，外层为孩子，内层为饼干

```
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int k=0;
        // 可以满足的孩子数目
        int sum=0;
        //截断判断
        boolean flag=true;
        for(int i=0;i<g.length&& flag;i++){
            flag=false;
            for(int j=k;j<s.length;j++){
                if(s[j]<g[i]){
                    continue;
                }else{
                    k=j+1;
                    sum++;
                    flag=true;
                    break;
                }
            }
        }
        return sum;
    }
}
```
