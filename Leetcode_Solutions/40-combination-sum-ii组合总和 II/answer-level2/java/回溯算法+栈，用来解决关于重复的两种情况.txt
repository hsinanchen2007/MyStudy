### 解题思路
相比39题来说，这个题一共多加了两个考点：

题目：candidates = [10,1,2,7,6,1,5], target = 8
candidates排序后为 [1,1,2,5,6,7,10]

考点一：用过第i位的元素不能再用，比如排序后第0位为1，则用回溯法之后第0位的1是不能再用的，但是第1位的i是可以再用的，所以我们可以用stack来解决，代码中有提示
考点二：第0位的1+第2位的2+第3位的5 => [1,2,5]，第1位的1+第2位的2+第3位的5 => [1,2,5] 这两种情况会导致重复
       

### 代码

```java
class Solution {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> one = new ArrayList<>();
        Arrays.sort(candidates);
        search(one, new ArrayList<>(), candidates, target ,new Stack<Integer>());
        return one;
    }

    public static void search(List<List<Integer>> one, List<Integer> two, int[] candidates, int target, Stack<Integer> record){
        if(target == 0) {
            List<Integer> vessel = new ArrayList<>(two);
            if(!one.contains(vessel))one.add(vessel); //用来解决考点二
        }
        else{
            for(int i=0; i<candidates.length; i++){
                if(target>=candidates[i]){
                    if( (!two.isEmpty() && i>record.peek() &&two.get(two.size()-1)<=candidates[i]) || two.isEmpty()){  
                        two.add(candidates[i]);                     //剪枝行动
                        record.push(i); //用来解决考点一
                        search(one,two,candidates,target-candidates[i],record);
                        two.remove(two.size()-1);
                        record.pop();
                    }
                    else continue;

                }
                else break;
            }
        }
    }
}
```
代码第二版
用int来取代stack
```
 public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> one = new ArrayList<>();
        Arrays.sort(candidates);
        search(one, new ArrayList<>(), candidates, target, 0);
        return one;
    }

public void search(List<List<Integer>> one, List<Integer> two, int[] candidates, int target, int count){
        if(target == 0) {
            List<Integer> vessel = new ArrayList<>(two);
            if(!one.contains(vessel))one.add(vessel);
        }
        else{
            for(int i=count; i<candidates.length; i++){
                if(target>=candidates[i]){
                    if(two.isEmpty() || two.get(two.size()-1)<=candidates[i]){  //剪枝行动
                        two.add(candidates[i]);
                        search(one,two,candidates,target-candidates[i],i+1);
                        two.remove(two.size()-1);
                    }
                    else continue;

                }
                else break;
            }
        }

    }
```
