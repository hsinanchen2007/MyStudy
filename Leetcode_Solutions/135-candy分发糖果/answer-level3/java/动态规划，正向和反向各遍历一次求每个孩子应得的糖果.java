执行结果：
通过
显示详情
执行用时 :
6 ms
, 在所有 Java 提交中击败了
83.05%
的用户
内存消耗 :
49.6 MB
, 在所有 Java 提交中击败了
24.16%
的用户
```
class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        if(len==0)return 0;
        if(len==1)return 1;
        int[] res = new int[len];
        res[0]=1;
        for(int i=1; i<len;i++){
            if(ratings[i]>ratings[i-1]){
                res[i]=res[i-1]+1;
            }else if(ratings[i]<=ratings[i-1]){
                res[i]=1;
            }
        }
        for(int i=len-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                res[i] = Math.max(res[i],res[i+1]+1);
            }
        }
        int sum=0;
        for(int i=0; i<len;i++){
            sum+=res[i];
        }
        return sum;
    }
}
```
