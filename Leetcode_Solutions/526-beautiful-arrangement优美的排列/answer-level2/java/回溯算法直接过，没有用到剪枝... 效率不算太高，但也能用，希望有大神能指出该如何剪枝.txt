```
class Solution {
    public int countArrangement(int N) {
        List<List<Integer>> res = new ArrayList<>();
        int[] selected = new int[N+1];
        for(int i = 0; i<selected.length; i++) {
            selected[i] = 0;
        }
        generate(res,new ArrayList<>(),N,selected);
        return res.size();
    }
    private void generate(List<List<Integer>> res,List<Integer> list,int N,int[] selected) {
        if(list.size() == N) {
            res.add(new ArrayList<>(list));
            return;
        }
        for(int i = 1; i<=N; i++) {
            if( selected[i]==0 && (i%(list.size()+1)==0 || (list.size()+1)%i==0) ) {
                selected[i] = 1;
                list.add(i);
                generate(res,list,N,selected);
                selected[i] = 0;
                list.remove(list.size()-1);
            }
        }
    }
}
```
