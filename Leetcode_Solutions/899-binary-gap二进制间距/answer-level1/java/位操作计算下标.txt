当数字N于flag与操作结果不为0时，说明对应位置为1.

```
class Solution {
    public int binaryGap(int N) {
        int flag = 1, result=0,prev=-1,current = 0,index=0;
        while(flag<=N){
            if((flag&N)!=0){
                if(prev==-1){
                    prev=index;
                }else{
                    current = index;
                    result = Math.max(result,current-prev);
                    prev = current;
                }
            }
            index++;
            flag<<=1;
        }
        return  result;
    }
}
```
