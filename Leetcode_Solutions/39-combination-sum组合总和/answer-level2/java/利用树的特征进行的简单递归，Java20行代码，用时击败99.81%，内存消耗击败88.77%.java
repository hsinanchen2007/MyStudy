1. 基本思路很简单，先将数组排序后，对数组进行遍历，并将其作为树根。
2. 在递归过程中，采取同样的思路，从当前项开始，将其作为子树的根，并更新所求的和
3. 比如我们对候选数组[2,3,5],目标值为8进行解答时，第一次就将2作为树根
4. 我们用一个列表存储当前选择的数，这儿把它叫做currentAns

![A\]I5AH0W2WX{QWW(HKK@Q{F.png](https://pic.leetcode-cn.com/1fb0b3460185ea08b01a90c612f686916ca90bc7e41e518347b5b6584437a508-A%5DI5AH0W2WX%7BQWW\(HKK@Q%7BF.png)

1. 如果剩下的和为0时，我们更新ans表
2. 如果当前和比第一项小时，即无法继续递归时，就移除CurrentAns最后一项

```
public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> currentAns = new ArrayList<>();
        if(candidates.length == 0)
            return ans;
        //排序后之后，方便遍历以及确定循环终止条件
        Arrays.sort(candidates);
        //用第i个数为树根时，寻找当前满足要求的list
        for (int i = 0; i < candidates.length && target >= candidates[i]; i++) {
            getList(ans,currentAns,candidates,i,target);
        }
        return ans;
    }
    private static void getList(List<List<Integer>> ans,List<Integer> currentAns,int [] candidates, int i, int res){
        //添加当前索引对应的值并更新和
        currentAns.add(candidates[i]);
        res = res - candidates[i];
        //如果当前需要的和为0，添加至ans中
        if(res == 0){
            ans.add(new ArrayList<>(currentAns)) ;
        }
        //从i开始，更新树根
        while(i<candidates.length&&candidates[i]<=res){
            getList(ans,currentAns,candidates,i,res);
            i++;
        }
        currentAns.remove(currentAns.size()-1);
    }
```
