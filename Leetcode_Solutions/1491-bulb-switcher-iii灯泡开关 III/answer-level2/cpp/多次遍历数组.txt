```
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n=light.size();
        int max_pos=0,count=0;
        bool lighted[n+1];                  //记录该索引处的灯亮否
        memset(lighted,false,sizeof(lighted));
        for(int i=0;i<n;i++){               //遍历light数组
            bool flag = true;
            max_pos=max(max_pos,light[i]);  
            lighted[light[i]]=true;
            for(int j=1;j<=max_pos;j++){    //遍历最大亮灯之前所有灯，全亮则count+1
                if(lighted[j]==false){
                    flag=false;
                    break;                  //不全亮则进入下次循环
                }
            }
            if(flag) count++;
        }
        return count;
    }
};
```
