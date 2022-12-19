### 解题思路
首先借助模板（非原创，总结各路大神的通用模板得到）：
```
public List<List<Integer>> backTrack(int k,int n){
    //生成回溯结果的存储位置
    List<List<Integer>> res = new ArrayList<>();
    //边界值判定，比如n == 0之类的。
    if() return res;
    //res内层list
    List<Integer> sub = new ArrayList<>();
    //回溯递归函数，先写出来占个坑，参数一会儿加。
    helper();
    //返回，程序结束。
    return res;
}

private void helper(int index){
    //回溯算法的主体，包括前进和回溯
    sub.add();
    helper(index + 1);
    sub.remove(sub.size() - 1);
}
```
整个算法思路很简单，由于是不包含重复数字且只有1-9，所以按序遍历相加，符合条件就保存下来。
接下来主要考虑三个方面：递归终止条件、参数传递以及回溯算法主体完成。
首先是参数传递，res和sub必须作为参数传递进去保存最终结果和中间变量。看模板代码可知，必定有一个参数index表示回溯算法的递进，题干中的k、n作为判定条件也要加入，所以共这五个参数。`List<List<Integer>> res,List<Integer> sub,int index,int k,int n`
然后是递归终止条件：比较明显的是两个条件必须同时达到，序列长度为k，之和为n。用n减去当前加入的数作为下一次递归的判定条件。另外如果n < 0（即sub之和已经大于n了），直接回溯。
```
if(n < 0) return ;
if(n == 0 && sub.size() == k){
    res.add(new ArrayList<>(sub));//这里必须用new ArrayList重新创建一个List。
    return ;
}
```
接下来就是回溯主体，由于是1-9的数且不重复，那一个for循环就可以了。初始条件就是index = 1。最后补全主函数中的helper就行了。
完整代码如下：


### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        if(k == 0 || n == 0) return res;
        helper(res,new ArrayList(),1,k,n);
        return res;
    }

    private void helper(List<List<Integer>> res,List<Integer> sub,int index,int k,int n){
        if(n < 0) return ;
        if(n == 0 && sub.size() == k){
            res.add(new ArrayList<>(sub));
            return ;
        } 
        for(int i = index;i <= 9;i++){
            sub.add(i);
            helper(res,sub,i + 1,k,n - i);
            sub.remove(sub.size() - 1);
        }
    }
}
```