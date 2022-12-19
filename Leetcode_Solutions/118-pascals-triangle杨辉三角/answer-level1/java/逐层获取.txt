执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.62%
的用户
内存消耗 :
34 MB
, 在所有 Java 提交中击败了
26.10%
的用户
```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(numRows==0)return res;
        List<Integer> list = new ArrayList<Integer>();
        list.add(1);
        res.add(list);
        int j = 2;
        while(j<=numRows){
            List<Integer> pre = res.get(j-2);
            List<Integer> vv = new ArrayList<Integer>();
            vv.add(1);
            int len = pre.size();
            for(int i=0; i<len; i++){
                if(i+1<len){
                    vv.add(pre.get(i)+pre.get(i+1));
                }
            }
            vv.add(1);
            res.add(vv);
            j++;
        }
        return res;
    }
}
```
