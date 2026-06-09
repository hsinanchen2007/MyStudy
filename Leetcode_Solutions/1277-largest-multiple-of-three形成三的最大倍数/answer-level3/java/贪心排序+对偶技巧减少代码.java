贪心思想：看数组的sum模3余几，如果余0，直接将整个数组返回；
否则进行讨论一下：
1.余1：去掉最小的mod(3)为1的数（数量足够），或者去掉两个mod(3)为2的数（前者数量不足）
2.余2：去掉最小的mod(3)为2的数（数量足够），或者去掉两个mod(3)为1的数（前者数量不足）
1和2是一种对偶关系，可以使用flag，3-flag 统一方程的思想来表示，这样可以减少代码量。
```
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        List<Integer>[] res=new List[3];
        for (int i=0;i<3;i++) res[i]=new ArrayList<>();
        int sum=0;
        //求和
        for(int i:digits){
            res[i%3].add(i);
            sum+=i;
        }
        //排序
        for(int i=0;i<3;i++) Collections.sort(res[i],Collections.reverseOrder());
        int flag=sum%3;
        //分情况讨论
        if(flag!=0){
            if(res[flag].size()>0) res[flag].remove(res[flag].size()-1);
            else if(res[3-flag].size()>1){
                res[3-flag].remove(res[3-flag].size()-1);
                res[3-flag].remove(res[3-flag].size()-1);
            }
            else {
                res[1].clear();
                res[2].clear();
            }
        }
        //合并求最后的结果
        res[0].addAll(res[1]);
        res[0].addAll(res[2]);
        Collections.sort(res[0],Collections.reverseOrder());
        StringBuilder sn=new StringBuilder();
        for(int i:res[0]){
           sn.append(i);
        }
        //前导零
        if(sn.length()!=0&&sn.charAt(0)=='0') return "0";
        return sn.toString();
    }
}
```
