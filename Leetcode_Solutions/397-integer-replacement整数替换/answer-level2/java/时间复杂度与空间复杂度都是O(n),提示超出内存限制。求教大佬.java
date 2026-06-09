```
class Solution {
    public int integerReplacement(int n) {
        if(n<=1){
            return 0;
        }
        int[] data = new int[n+2];
        Arrays.fill(data,0);
        data[1]=1;
        data[2]=1;
        if(n<=2){
            return 1;
        }
        //以上，初始化一些值
        //以下，开始计算
        //当前数为偶数，已经算出，同时更新乘二的值
        //当前数为奇数，比较+1和-1，更新当前值，同时更新乘二的值。
        for(int i = 2;i<n+1;i++){
            if(i%2 ==0){
                if(2*i<data.length){
                    data[2*i]=data[i]+1;
                }

            }else{
                data[i]=Math.min(data[i-1],data[i+1])+1;
                if(2*i<data.length){
                   data[2*i]=data[i]+1;
                }
            }    
        }
        return data[n];
    }
}
```
//数据能计算到100000000
//求教问题出在哪里？