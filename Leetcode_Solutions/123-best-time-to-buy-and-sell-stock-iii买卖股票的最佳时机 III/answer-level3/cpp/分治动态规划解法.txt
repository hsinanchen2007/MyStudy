class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)  return 0;
        int maxprofit=0,min=prices[0],tempprofit=0;
        for(int i=0;i<prices.size();i++){
             if(prices[i]>min){
                  tempprofit=prices[i]-min;
                  if(tempprofit>maxprofit)
                      maxprofit=tempprofit;
             }
             else
                min=prices[i];   
             }//单词购买的最大利润，接下来是将数组分割成两个部分进行
        /*分割数组进行动态规划*/
       
       for(int i=1;i<prices.size()-1;i++){
           int Profitone=0,Profittwo=0,minone,mintwo,tempprofitone,tempprofittwo;
           minone=prices[0];
           mintwo=prices[i+1];
           for(int m=0;m<i+1;m++){
                if(prices[m]>minone){
                    tempprofitone=prices[m]-minone;
                    if(Profitone<tempprofitone)
                         Profitone=tempprofitone;
                }
                else 
                  minone=prices[m];
           }

            for(int m=i+1;m<prices.size();m++){
                if(prices[m]>mintwo){
                    tempprofittwo=prices[m]-mintwo;
                    if(Profittwo<tempprofittwo)
                         Profittwo=tempprofittwo;
                }
                else
                 mintwo=prices[m];
             }
            tempprofit=Profitone+Profittwo;
            if(tempprofit>maxprofit) 
               maxprofit=tempprofit;
       }

       return maxprofit;
    }
};

/*分治法，分段进行动态规划  */
就是将数组分成两个部分，在这两个部分进行动态规划，然后把这两个部分加起来。选取一个游标p,p依次往后移动，将数组分成2个部分。