DFS遍历所有组合，需要注意是
1. 返回组合不重复，因此下一次递归从preIndex+1位置开始；
2. 组合数量大于k个数或者和超过n进行剪枝。

``` java
class Solution {
    private List<List<Integer>> res;
    private int k;
    private int n;
    public List<List<Integer>> combinationSum3(int k, int n) {
        res=new ArrayList<>();
        if (k==0||n<1||n>9*k-1-2) return res;
        this.k=k;
        this.n=n;
        backTracking(new ArrayList<Integer>(),0,1);
        return res;

    }
    private void backTracking(List<Integer> prefix,int sum,int start){
        if (prefix.size()>=k){
            if (sum==n) res.add(new ArrayList<>(prefix));
            return;
        }
        if (sum>n) return;
        for(int i=start;i<=9;i++){
            if (i>n) break;
            sum+=i;
            prefix.add(i);
            backTracking(prefix,sum,i+1);
            prefix.remove(prefix.size()-1);
            sum-=i;
        }
    }
}
```

执行用时：0 ms
内存消耗：37.1 MB