执行用时 :148 ms, 在所有 csharp 提交中击败了100.00%的用户
内存消耗 :29.9 MB, 在所有 csharp 提交中击败了6.67%的用户
```
public class Solution {
    public int FindContentChildren(int[] g, int[] s) {
        Array.Sort(g);//排序
        Array.Sort(s);//排序
        int total = 0;
        int j = 0;
        for(int i = 0;i<g.Length;i++){
            if(s.Length <= j){
                break;
            }
            for(;j<s.Length;){
                if(g[i]<=s[j]){
                    total+=1;
                    j++;
                    break;
                }
                j++;
            }
        }


        return total;
    }
}
```