一个基本的回溯法模板，但是要注意剪枝问题，能够减少不必要的运算，提高运行速度。
这个问题的剪枝发生在剩余个数是否满足需要的数字个数这里。
n - i + 1 >= k - currentList.size(),即余下的数字应大于等于还需要的数字个数，否则没必要再进行运算了。
```
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> resultList = new ArrayList<>();
        if(n == 0){
            return resultList;
        }
        combine(resultList,new ArrayList<>(),n,k,1);
        return resultList;
    }
    private void combine(List<List<Integer>> resultList,List<Integer> currentList,int n,int k,int index){
        if(currentList.size() == k){
            resultList.add(new ArrayList<>(currentList));
            return;
        }
        for(int i = index;i <= n - (k - currentList.size()) + 1;i++){
            currentList.add(i);
            combine(resultList,currentList,n,k,i + 1);
            currentList.remove(currentList.size() - 1);
        }
    }
}
```
