根据气温范围是固定的通过数组记录每个温度的最小下标，逆序遍历更新每个温度出现的最小下标，对于当前温度，遍历得到大于该温度需要的最小天数。
```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        //气温值范围固定.temperature[i] 表示i度的最小下标
        int[] temperature=new int[101];
        int[] goal = new int[T.length];
        for(int i=T.length-1;i>=0;i--){
            int min=0;
            for(int j=T[i]+1;j<=100;j++){
                if(temperature[j]!=0){
                    if(min==0) min=temperature[j]-i;
                    else{
                        if(min>temperature[j]-i) min=temperature[j]-i;
                    }
                }
            }
            goal[i]=min;
            if(temperature[T[i]]==0) temperature[T[i]]=i;
            else if(temperature[T[i]]!=0 && temperature[T[i]]>i){
                temperature[T[i]]=i;
            }
        }
        return goal;
    }
}
```
