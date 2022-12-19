class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
          int distance=0,row=0,list=0,time=0;
          if(points.size()<2) return 0;
          for(int i=0;i<points.size()-1;i++){
              row=abs(points[i][0]-points[i+1][0]);
              list=abs(points[i][1]-points[i+1][1]);
              if(row==0||list==0)
                  time+=max(row,list);
            else{
               distance=max(row,list)-min(row,list);
               time+=(distance+min(row,list));
            }
        }
        return time;
    }
};
思考关键：能走斜线就走斜线，先用斜线逼近再走横线和竖线。
UESTC 微笑