### 解题思路
首先用Arrays.sort()对数组进行排序（升序）
接下来判断①该数是否大于target
②该数是否等于target
③该数是否重复，对函数进行优化。
建立递归函数helper(int target,int index,List<Integer> list)
每次优先用较大的数对目标target进行减法（因为这里想到LeetCoede中一道找钱的贪心算法题目）
若，target==0则加入答案lists.

注意：
直接进行lists.add(list),可能会因为后面对list的操作导致lists的答案不正确
因此使用ArrayList<>(ans)接收list的值，最后lists.add(ans)添加ans

### 代码

```java
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    int[] candidate;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        int len = candidates.length;
        this.candidate = candidates;
        Arrays.sort(candidates);
        for(int i=len-1;i>=0;i--){
            if(candidates[i]>target){
                continue;
            }else if(i!=len-1&&candidates[i]==candidates[i+1]){
                continue;
            }else if(candidates[i]==target){
                List<Integer> list = new ArrayList<>();
                list.add(candidates[i]);
                if(lists.contains(list)){
                    continue;
                }
                lists.add(list);
                continue;
            }
            List<Integer> list = new ArrayList<>();
            list.add(candidate[i]);
            helper(target-candidate[i],i,list);
        }
        return lists;
    }

    public void helper(int target,int index,List<Integer> list){
        if(target<0){
            return;
        }else if(target==0){
            if(lists.contains(list)){
                return;
            }
            List<Integer> ans = new ArrayList<>(list);
            lists.add(ans);
            return;
            
        }else if(target-candidate[0]<0){
            return;
        }
        for(int i=index-1;i>=0;i--){
            if(target-candidate[i]!=0&&target-candidate[i]<candidate[0]){
                continue;
            }
            list.add(candidate[i]);
            helper(target-candidate[i],i,list);
            list.remove(list.size()-1);
        }
    }
}
```