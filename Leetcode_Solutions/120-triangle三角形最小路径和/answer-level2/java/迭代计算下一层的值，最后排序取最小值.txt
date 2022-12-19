执行结果：
通过
显示详情
执行用时 :
11 ms
, 在所有 Java 提交中击败了
16.19%
的用户
内存消耗 :
37.4 MB
, 在所有 Java 提交中击败了
68.44%
的用户
```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int sum=0;
        if(triangle.isEmpty())return 0;
        int[] arr = new int[triangle.get(triangle.size()-1).size()];
        List<Integer> res = new ArrayList<Integer>();
        res.addAll(triangle.get(0));
       
        for(int i=1; i<triangle.size();i++){
            List<Integer> cur = triangle.get(i);
            int last = cur.get(0)+res.get(0);
            for(int j=1; j<cur.size()-1;j++){
                int temp = Math.min(cur.get(j)+res.get(j-1),cur.get(j)+res.get(j));
                res.set(j-1,last);
                last = temp;
            }
            res.add(cur.get(cur.size()-1)+res.get(cur.size()-2));
            res.set(cur.size()-2,last);
           
        }
        Collections.sort(res);
        return res.get(0);
    }
}
```
