int maxProfit(int* prices, int pricesSize){
      int maxProfit=0,min=0,max=0,maxtemp=0,i=1;
      if(pricesSize==0||pricesSize==1)  return  0;
      min=prices[0];
      max=0; 
      for(i;i<pricesSize;i++){

           if(prices[i]>min){
               maxtemp=prices[i]-min;
               if(maxtemp>max)
                   max=maxtemp;
           }else if(min>=prices[i])
                  min=prices[i];             
      }

      return  max;
}