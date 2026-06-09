### 解题思路
此处撰写解题思路
**排列问题中不是真正的删除，而是通过交换得到新新的排序**
[k,...,end]表达候选列表。
### 代码

```java
class Solution {//不增加元素，只是交换位置！！！
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer>cur=new ArrayList<>(nums.length);
        for(int num :nums) cur.add(num);
        backtracking(cur,0,res);
        return res;
    }
    public void backtracking(List<Integer> cur,int k,List<List<Integer>> res){//k就是分界线。
        if(k==cur.size()){
            res.add(new ArrayList<>(cur));//java中想要新建东西，必须是nuex!!!!!!
            return;
        }
        for(int i=k;i<cur.size();i++){//在候选部分中选择。
            Collections.swap(cur,k,i);//选择第i个元素
            backtracking(cur,k+1,res);
            Collections.swap(cur,k,i);//撤销。
        }
        
    } 

}
```