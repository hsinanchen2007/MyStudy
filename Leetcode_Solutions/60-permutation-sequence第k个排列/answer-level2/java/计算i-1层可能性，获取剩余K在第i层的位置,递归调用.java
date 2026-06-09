执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
70.42%
的用户
内存消耗 :
34.6 MB
, 在所有 Java 提交中击败了
88.32%
的用户
```
class Solution {
    
    public String getPermutation(int n, int k) {
        if(n==0||k==0)return "";
        StringBuffer sb = new StringBuffer();
        List<Integer> list = new ArrayList<>();
        for(int i=1; i<=n; i++){
            list.add(i);
        }
        get(n,k,sb,list);
        return sb.toString();
    }
    private void get(int n,int k,StringBuffer sb, List<Integer> list){
        int sub =1;
        // if(list.size()==1){
        //     sb.append(list.get(0));
        //     return;
        // }
        for(int i=n-1; i>0; i--){
            sub*=i;
        }
        int x = k/sub;
        int mod = k%sub;
        if(mod==0){
            sb.append(list.get(x-1));
            for(int c=list.size()-1; c>=0; c--){
                if(c!=x-1){
                    sb.append(list.get(c));
                }
            }
            return ;
        }else{
            sb.append(list.get(x));
            list.remove(x);
            get(n-1,mod,sb,list);
        }
    }
}
```
