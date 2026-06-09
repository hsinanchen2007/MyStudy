
        if(timeSeries.length<1) return 0;
        int sum=0;
        for(int i=0;i<timeSeries.length-1;i++){
            sum+=timeSeries[i+1]>timeSeries[i]+duration?duration:timeSeries[i+1]-timeSeries[i];
        }
        return sum+duration;
