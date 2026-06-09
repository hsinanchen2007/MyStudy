### 解题思路
回溯，start，甚至只要判断temp的数组的大小是否达到了K即可

### 代码

```java
class Solution {
    List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {

        List<Integer> temp=new ArrayList<>();
        helper(n,1,k,temp);
        return res;
    }
    public void  helper(int n,int start, int k, List<Integer> temp)
    {
        if (temp.size()==k)
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        for (int i=start;i<=n;i++)
        {
            temp.add(i);
            helper(n,i+1,k,temp);
            temp.remove(temp.size()-1);
        }
    }
}
```