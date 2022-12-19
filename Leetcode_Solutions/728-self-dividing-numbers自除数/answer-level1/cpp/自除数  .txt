class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
         vector<int> svec;
         int temp=0,divide=1,flag=1;//暂存left数据,和除数
         for(left;left<right+1;left++){
            if(left<10)
                  svec.push_back(left);
             else if(left%10==0)  continue;
             else{
                  flag=1;
                  temp=left;//暂存left数值
                  while(temp!=0){
                           divide=temp%10;  
                           if(divide==0||left%divide!=0){
                                flag=0;
                                break;
                                }
                           temp/=10;
                  }
                if(flag==1)  svec.push_back(left);
              }
          }
    return svec;
    }
};
UESTC 微笑