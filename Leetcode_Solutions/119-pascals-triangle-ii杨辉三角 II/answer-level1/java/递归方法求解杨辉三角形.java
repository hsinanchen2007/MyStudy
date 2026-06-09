当求解第0行时，直接返回含有1的列表。

当求解第n行的时候，先求解第n-1行，然后对于第

n-1行的返回结果列表list，不断把list中连续两个位置的数的和

送入本次结果列表中，最后在本次结果列表中添加1即可。

java 代码：

```
class Solution {
    public List<Integer> getRow(int rowIndex) {
        
        List<Integer>ans = new ArrayList();
        ans.add(1);
        
        if(rowIndex == 0)
            return ans;
        
        
        List<Integer>last = getRow(rowIndex-1);
        for(int i = 1;i < last.size();i++)
            ans.add(last.get(i-1)+last.get(i));
        ans.add(1);
        return ans;
        
    }
}
```