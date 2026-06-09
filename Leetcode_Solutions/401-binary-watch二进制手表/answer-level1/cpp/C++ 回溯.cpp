class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int time[10]={0};
        vector<string> res;
        recruise(time,num,0,res,0);
        return res;
    }
    void recruise(int time[],int num,int step,vector<string>&res,int position)
    {
        if(step==num)
        {
            int hours=1*time[0]+2*time[1]+4*time[2]+8*time[3];
            int minute=1*time[4]+2*time[5]+4*time[6]+8*time[7]+16*time[8]+32*time[9];
            if(minute>=0&&minute<=59&&hours>=0&hours<=11)
            {
            if(minute>=10)
            {
                string str = to_string(hours)+":"+to_string(minute);
                res.push_back(str);
            }
            else
            {
                string str = to_string(hours)+":0"+to_string(minute);
                res.push_back(str);
            }
            }
            return;
        }
        for(int i=position;i<10;i++)
        {
            time[i]=1;
            recruise(time,num,step+1,res,++position);
            time[i]=0;
        }
        
    }
};
