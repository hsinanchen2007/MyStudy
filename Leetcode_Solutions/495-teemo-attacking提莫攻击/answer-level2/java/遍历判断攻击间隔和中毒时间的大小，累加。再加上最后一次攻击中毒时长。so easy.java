 public int findPoisonedDuration(int[] timeSeries, int duration) {
        if(duration==0){
            return 0;
        }
        int len=timeSeries.length;
        if(timeSeries==null||len==0){
            return 0;
        }
        if(len==1){
            return duration;
        }
        int sum=0;
        for(int i=1;i<len;i++){
            int between=timeSeries[i]-timeSeries[i-1];
            if(between >= duration){
                sum+=duration;
                continue;
            }
            sum+=between;
        }
        sum+=duration;
        return sum;
    }