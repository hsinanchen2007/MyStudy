没啥难点

         if (timeSeries.length==0){
            return 0;
        }
        
        if (timeSeries.length==1){
            return duration;
        }
        int time=0;
        for (int i = 0; i < timeSeries.length-1; i++) {
            if (timeSeries[i]+duration<=timeSeries[i+1]){
                time+=duration;
            }else {
                time+= timeSeries[i+1]-timeSeries[i];
            }
        }
        time+=duration;
        return time;
 