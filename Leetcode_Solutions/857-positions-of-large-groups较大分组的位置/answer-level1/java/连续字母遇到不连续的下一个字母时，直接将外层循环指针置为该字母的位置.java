执行用时 : 4 ms, 在Positions of Large Groups的Java提交中击败了93.71% 的用户
内存消耗 : 35.7 MB, 在Positions of Large Groups的Java提交中击败了100.00% 的用户
```
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> res = new ArrayList<>();
        int start = 0;//外层循环下一次判断连续字母时的位置
        for(int i=start; i<S.length()-1; i=start){
            List<Integer> temp = new ArrayList<>();
            temp.add(i);
            int len = 1;
            int j=0;
            for(j=i+1; j<S.length(); j++){
                if(S.charAt(j)!=S.charAt(i)){
                    if(len>=3){
                        temp.add(j-1);
                        res.add(temp);
                    }
                    start=j;
                    break;
                }
                else{
                    len++;
                }
            }
            if(j==S.length()&&len<3){//判断特殊情形
                break;
            }
            else if(j==S.length()&&len>=3){
                temp.add(j-1);
                res.add(temp);
                break;
            }
        }
        return res;
    }
}
```