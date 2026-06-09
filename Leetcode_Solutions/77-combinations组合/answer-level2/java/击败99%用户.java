### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> list = new ArrayList<>();
        if(k > n || k == 0){
            ret.add(list);
            return ret;
        }
        backtracking(list, 1, n, k);
        return ret;
    }
    // 该函数找到start~n范围内可能的K个数的组合
    private void backtracking(List<Integer> already, int start, int n, int k){
        // 还要再找零个数，意味着already的长度已经够了
        if(k == 0){
            ret.add(new ArrayList<>(already));
            return;
        }
        // 如果i>n-k+1则i后面凑不够k个数
        for(int i = start; i <= n - k + 1; i++){
            already.add(i);
            // 在i+1~n之间找可能的k-1个数的组合
            backtracking(already, i+1, n, k-1);
            already.remove(already.size() - 1);
        }
        return;
    }
}
```