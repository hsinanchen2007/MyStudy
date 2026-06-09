Logic for median

If total count is odd, median is the number at totalCount/2+1. If total count is even, median is average of number at totalCount/2 and totalCount/2+1.

Use currentCount to accumulate count until it reaches totalCount/2. If currentCount is greater than totalCount/2, median is that number no matter totalCount is odd or even. Tricky case is currentCount is same as totalCount/2. If totalCount is odd, median is the next number. If totalCount is even, median is average of current and next number.
```
    vector<double> sampleStats(vector<int>& count) {
        double MIN=-1,MAX=0,AVE,MED,MOD,acc=0;
        int maxCnt = 0, totalCnt = 0;
        for(int i=0;i<256;++i){
            if(MIN==-1&&count[i])   MIN=i;
            if(count[i])    MAX=i;
            acc+=i*count[i];
            if(count[i]>maxCnt) {maxCnt=count[i];MOD=i;}
            totalCnt += count[i];
        }
        AVE = acc/totalCnt;
        int curCnt = 0;
        for(int i=0;i<256;++i){
            curCnt+=count[i];
            if(curCnt>=totalCnt/2){
                if(curCnt>totalCnt/2)   {MED=i;break;}
                //i.e. curCnt == totalCnt/2
                if(totalCnt%2==0)   {MED=(i+i+1)/2.0;break;}
                else    {MED=i+1;break;}
            }
        }
        return {MIN,MAX,AVE,MED,MOD};
    }
```