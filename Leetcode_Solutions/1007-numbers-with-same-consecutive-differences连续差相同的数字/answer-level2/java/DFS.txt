```
class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        if(N == 1){
            // 这个题目好像没说，比较坑
            return new int[]{0,1,2,3,4,5,6,7,8,9};
        }
        List<Integer> res = new ArrayList<>();
        for(int i = 1; i <= 9; i++){
            List<String> list = f(N-1, K, i);
            for(String s : list){
                if(s.length() == N){
                    res.add(Integer.valueOf(s));
                }
            }
        }
        int[] ans = new int[res.size()];
        for(int i = 0; i < ans.length; i++){
            ans[i] = res.get(i);
        }
        return ans;
    }

    // 经验教训：先把递归含义说清楚。。。
    // 找到以i开头，差值都是K的所有数。
    private List<String> f(int N, int K, int i){
        if(N == 0){
            return Arrays.asList(String.valueOf(i));
        }
        List<String> res = new ArrayList<>();
        for(int p = 0; p <= 9; p++){
            if(Math.abs(i-p) == K){
                List<String> list = f(N-1, K, p);
                for(String s : list){
                    res.add(i+s);
                }
            }
        }
        return res;
    }
}
```
