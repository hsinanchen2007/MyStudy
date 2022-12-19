### 解题思路
回溯法，每一遍传一个list，感觉代码可以优化

### 代码

```java
class Solution {
    List<List<Integer>> list=new ArrayList<List<Integer>>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        search(candidates,target,0,candidates.length,new ArrayList<Integer>());
        return list;
    }

    public void search(int[] candidates,int target,int left,int right,List<Integer> listTemp){
        for(int i=left;i<right;i++){
            if(target-candidates[i]==0){
                List<Integer> list2=new ArrayList<Integer>();
                list2.addAll(listTemp);
                list2.add(candidates[i]);
                list.add(list2);
            }else if(target-candidates[i]>0){
                List<Integer> list2=new ArrayList<Integer>();
                list2.addAll(listTemp);
                list2.add(candidates[i]);
                search(candidates,target-candidates[i],i,right,list2);
                continue;
            }
            break;
        }
    }
}
```