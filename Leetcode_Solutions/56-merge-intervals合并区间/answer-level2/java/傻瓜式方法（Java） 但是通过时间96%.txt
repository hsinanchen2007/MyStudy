比较傻瓜的方法，不过时间却只花了2ms。

    先找到所有小区间的最小值和最大值（左端点和右端点），创建一个(max-min)*2+1长度的数组line，用来表示每一个端点，端点与端点之间的区间是否被包含，例如（1，3）=>（1，1-2，2，2-3，3），然后在对line遍历，找到这样的区间和独立的端点。

```
class Solution{
    public int[][] merge(int[][] intervals) {
        int m=intervals.length;
        if(m<=1) return intervals;
        int max=Integer.MIN_VALUE;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<m;i++){//找到区间的最左端和最右端
            if(intervals[i][0]<min) min=intervals[i][0];
            if(intervals[i][1]>max) max=intervals[i][1];
        }
        int[] line=new int[(max-min)2+1];//创建长度为(max-min)2+1的数组，例如（1，3）=>（1，1-2，2，2-3，3）
        for(int i=0;i<m;i++){//记录总的区间长度，每一个端点和端点与端点之间的区间是否被包含，“1”表示包含
            for(int j=intervals[i][0];j<intervals[i][1];j++){
                line[(j-min)*2]=1;
                line[(j-min)*2+1]=1;
            }
            line[(intervals[i][1]-min)*2]=1;//每个小区间的右端点必被包含
        }
        int[][] res=new int[m][2];
        int i=0;
        int count=0;//记录区间数量
        int len=(max-min)*2+1;
        while(i<len){//循环找到连续的区间
            while(i<len && line[i]==0){
                i++;
            }
            if(i>=len) break;
            int l=i;
            while(i<len && line[i]!=0){
                i++;
            }
            int r=i;
            if(r-l==1){//该情况表示只有一个端点，没有真正的区间
                res[count][0]=l/2+min;
                res[count][1]=l/2+min;
            }else{
                res[count][0]=l/2+min;
                res[count][1]=min+(r-1)/2;
            }
            count++;
        }
        int[][] result=new int[count][2];//返回数组
        for(int k=0;k<count;k++){
            result[k][0]=res[k][0];
            result[k][1]=res[k][1]; 
        }
        return result;
    }
}
```


