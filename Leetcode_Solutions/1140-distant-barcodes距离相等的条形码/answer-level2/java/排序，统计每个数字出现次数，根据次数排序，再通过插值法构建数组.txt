
```
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Arrays.sort(barcodes);
        List<int[]> value_count = new ArrayList<>();
        //统计每个数字出现的次数
        int n=barcodes.length;
        for(int i=0;i<n;i++){
            int count=1;
            while(i<n-1 && barcodes[i]==barcodes[i+1]){
                i++;
                count++;
            }
            int[] t={barcodes[i],count};
            value_count.add(t);
        }
        int[][] goal = value_count.toArray(new int[0][]);
        //按照出现次数从大到小排序
        Arrays.sort(goal,new Comparator<int[]>(){
            public int compare(int[] a,int[] b){
                return b[1]-a[1];
            }
        });
        int[] temp = new int[barcodes.length];
        //先填充偶数位
        int flag=0;
        int cur=0;
        int pre=1;
        int i=0;
        for(;i<goal.length;i++){
            if(cur>n-1) break;
            for(int j=0;j<goal[i][1];j++){
                if(cur<=n-1){
                    temp[cur]=goal[i][0];
                    cur+=2;
                }else{
                    temp[pre]=goal[i][0];
                    pre+=2;
                    
                }
            }
            
        }
        //填充奇数位
        for(;i<goal.length;i++){
            for(int j=0;j<goal[i][1];j++){

                temp[pre]=goal[i][0];
                pre+=2;
               
            }
        }
        return temp;

    }
}
```
