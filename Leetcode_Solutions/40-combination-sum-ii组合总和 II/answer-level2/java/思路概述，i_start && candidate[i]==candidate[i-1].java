### 解题思路
这里的candidates里面可重复数字着实难住我了，看了一下高赞，一下子就畅通了
首先相比combination1而言，每次递归从start变成了start+1，避免了同一个index里面的数字可重复出现，但还有一个问题，就是1,1,2,5,6,7,10，target=8 可能出现1，1,6  或者2,6，.....
但是也会出现1,2,5，那么这个时候怎么跳过第二个1，但是又得让第二个1在前面是1的情况下出现，毕竟1，1,6是合法的，两个1,2,6是不合法的，
这里采取的是在每次循环的时候进行判定，当前数字跟前一个数字相同时，选择跳过，但是又保证了第一个数字，即第一个1的合理性，并且由于迭代的因素，每个1都有机会当start拿出来遍历，所以每个1都有机会被选中，其被选中的情况就是前一个1也被选中的情况（temp里面放进了前一个1，进入新的迭代）。
当前一个1没有被选中的情况（存在这种情况，temp里面没有前一个1），这个时候当前的1也不可能进来，也没进来的意义，毕竟它就算进去了，也会重复，其的所有情况可以被前一个1进去的那次迭代所替代。
所以前一个1没有被选中的话，迭代会直接放弃所有后续的1，（因为index都大于start，且与前一个的candidate数值相同，所以会跳过。直接跑到2，一个1都不会存在的情况。）

### 代码

```java
class Solution {
    public List<List<Integer>> res= new ArrayList<>();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        ArrayList<Integer> temp = new ArrayList<>();
        helper(candidates,0,temp,target);
        return  res ;

    }
    public void helper(int[] candidates,int start,ArrayList<Integer> temp, int target)
    {
        if(target==0)
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        if(start==candidates.length)
            return;
        
        for(int i=start;i<candidates.length;i++)
        {
            if(i>start && candidates[i]==candidates[i-1])
                continue;
            if(target-candidates[i]>=0)
            {
                temp.add(candidates[i]);
                helper(candidates,i+1,temp ,target-candidates[i]);
                temp.remove(temp.size()-1);
            }
            else
                break;
        }
    }
}

```