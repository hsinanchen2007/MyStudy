执行用时 :17 ms, 击败了48.72%的用户。
内存消耗 :40.5 MB, 击败了25.40%的用户。
```
class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        List<String> list = new ArrayList();
        if(N==1){
            list.add("0");
        }
        for(int i = 1; i <= 9;i++){
            add(list,String.valueOf(i),i,N,K);
        }
        int[] res = new int[list.size()];
        for(int i = 0; i < res.length; i++){
            res[i] = Integer.valueOf(list.get(i));
        }
        return res;
    }
    
    private void add(List<String> list, String s,int pre,int N,int K){
        if(s.length()>=N){
            list.add(s);
            return;
        }
        int num;
        if(pre-K>=0){
            num = pre-K;
            add(list,s+num, num, N, K);
        }
        if(pre+K<10 && K!=0){
            num = pre+K;
            add(list,s+num, num, N, K);
        }
    }
}
```
