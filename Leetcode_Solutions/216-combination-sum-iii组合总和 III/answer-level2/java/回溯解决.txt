### 解题思路
这题和之前的题目也类似，递归解决题目要注意的几个点：
1.程序什么时候返回
2.当前程序应该做什么事情

这个题而言，我设置了一个变量i用来标记下一个应该加上的数，同时用了List来保存所有加过的数，便于回溯。
因此，当i>10时，当i>n时，当list的size>k时，程序返回。
当list中的数的和大于n时，程序返回。

当前程序应该做的事就是
将i保存进list，然后进入新的递归，最后从list中移除刚加入的数。


### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        second(k,n,result,1,new ArrayList<>());
        return result;
    }

    private void second(int k, int n, List<List<Integer>> result, int i, List<Integer> temp) {
        if (i > n || i > 10 || temp.size() > k)
            return;
        int val = cal(temp);
        if (val > n)
            return;
        if (temp.size() == k && val != n)
            return;
        if (temp.size() == k){
            result.add(new ArrayList<>(temp));
            return;
        }
        for(int j=i;j<=n;j++){
            temp.add(j);
            second(k,n,result,j+1,temp);
            temp.remove(temp.size()-1);
        }
    }

    private int cal(List<Integer> temp) {
        int val = 0;
        for (Integer integer : temp) {
            val = val + integer;
        }
        return val;
    }
}
```