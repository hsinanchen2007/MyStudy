回溯算法，实际上这道题比题39和40还要相对简单一些
```
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    int k=0;
    public List<List<Integer>> combinationSum3(int k, int n) {
        this.k = k;  //省得回溯函数参数列表太长了，所以单独把k提出来
        backstrap(new Stack<Integer>(), 0, 1, n);  //临时栈存放结果数组
        return res;
    }
    private void backstrap(Stack<Integer> tmp, int heigh, int start, int residual){
        if(heigh>k) return;   //高度过高直接剪枝
        if(heigh==k && residual==0){
            res.add(new ArrayList<Integer>(tmp));   //找到匹配结果写入res列表
            return;
        }
        for(int i = start; i<10 && residual-i>=0; i++){  //将数减成负数，不可能继续下去，进行剪枝
            tmp.push(i);
            backstrap(tmp, heigh+1, i+1, residual-i);
            tmp.pop();  //回退栈结果，回溯
        }

    }
}
```
对于k=3，n=9，当找到第一个结果栈中为[1,2,6]时，会回退到[1,2],尝试剩下的7,8,9，但是这几个由于for中的剪枝条件不会进行下去，
则继续回退到[1]再尝试