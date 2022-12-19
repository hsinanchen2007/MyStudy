菜鸡抠脚代码：
```
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        char[] ch = seq.toCharArray();
        int[] answer = new int[ch.length];

        //当每次A和B子序列嵌套的深度接近时，此时选择任意一组A,B, max(depth(A),depth(B))可以取到最小值;
        //故当(下标为偶数时,设为A串, )下标为奇数时,设为B串;对应右括号奇偶相反
        for(int i=0;i<ch.length;i++){
            if(ch[i]=='('){
                if(i%2==0)
                    answer[i]=0;
                else
                    answer[i]=1;
            }
            else{
                if(i%2==1)
                    answer[i]=0;
                else
                    answer[i]=1;
            }
        }
        return answer;
    }
}
```
