考虑第i位，我们有两个选择：要么添加当前元素同时原地不变，要么不添加当前元素进入下一个元素

根据上面两种选择，进行递归操作

```
class Solution {
    
    List<List<Integer>> result = new LinkedList<List<Integer>>();
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> current = new LinkedList<Integer>();
        getResult(candidates,target,0,current);
        return result;
    }
    
    public void getResult(int[] data,int target,int i,List<Integer> current){
        if(i>=data.length)
            return;
        
        if(data[i]<target){   //第一个选择，如果当前元素小于target，那么就添加，同时索引不变，下一次依然可以继续添加
            List<Integer> temp1 = new LinkedList<Integer>(current);
            temp1.add(data[i]);
            getResult(data,target-data[i],i,temp1);     
                
        }
        getResult(data,target,i+1,current);  // 不添加当前元素，进入下一位
        if(data[i]==target){
            current.add(data[i]);
            result.add(current);
            return;
        }
    }
}
```
