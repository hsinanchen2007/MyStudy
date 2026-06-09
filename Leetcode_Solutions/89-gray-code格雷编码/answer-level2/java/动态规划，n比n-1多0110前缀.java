执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
34 MB
, 在所有 Java 提交中击败了
29.54%
的用户
```
class Solution {
    public List<Integer> grayCode(int n) {
        int k=0;
        List<Integer> ll = new ArrayList<>();
        ll.add(0);
        int cur = 1;
        while(k<n){
           List<Integer> list = new ArrayList<>(ll.size()<<1);
           for(int ii=0; ii<ll.size(); ii++){
               if(ii%2==0){
                   list.add(ll.get(ii));
                   list.add(ll.get(ii)+cur);
               }else{
                   list.add(ll.get(ii)+cur);
                   list.add(ll.get(ii));
               }
           }
          cur=cur<<1;
           k++;
           ll = list;
        }
        return ll;
    }
}
```
