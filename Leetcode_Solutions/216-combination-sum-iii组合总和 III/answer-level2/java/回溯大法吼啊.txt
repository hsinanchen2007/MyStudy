### 解题思路
回溯吃遍天啊

### 代码

```java
class Solution {
    private List<List<Integer>>res;
    public List<List<Integer>> combinationSum3(int k, int n) {
        res=new ArrayList<>();
        List<Integer>tmp=new ArrayList<>();
        _Work(k,n,1,tmp);
        return res;
    }

    private void _Work(int k, int n,int index,List<Integer>tmp) {
        if(k==0&&n==0){
            res.add(new ArrayList<>(tmp));
            return;
        }
        if(k<=0)
            return;
        for(int i=index;i<=9;i++){
            tmp.add(i);
            _Work(k-1,n-i,++index,tmp);
            tmp.remove(tmp.size()-1);
        }
    }
}
```