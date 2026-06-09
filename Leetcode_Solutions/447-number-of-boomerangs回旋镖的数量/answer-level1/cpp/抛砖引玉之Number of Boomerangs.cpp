执行用时 :
224 ms, 在所有 C++ 提交中击败了99.18%的用户
内存消耗 :
10.3 MB, 在所有 C++ 提交中击败了96.37%的用户

```
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int dis[points.size()][points.size()];
        int number=0;
        for(int i=0;i<points.size();++i){
            for(int j=0;j<points.size();++j){
                dis[i][j]=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                dis[j][i]=dis[i][j];
            }
        }
        for(int i =0;i<points.size();++i){
            sort(dis[i],dis[i]+points.size());
            int num=0;
            for(int j=1;j<points.size();++j){
                
                if(dis[i][j]==dis[i][j-1]){
                    num++;
                }
                else{
                    if(num!=0){
                        cout << i <<"after:" << num+1 << endl;
                        number+=factorial(num+1);
                        num=0;
                    }
                }
            }
            if(num!=0){
                cout << i <<"after:" << num+1 << endl;
                number+=factorial(num+1);
                num=0;
                    }
        }
        return number;
    }
    int factorial(int num){
        int group=1;
        if(num ==2) return 2;
        if(num==3) return 6;
        for(int i=num;i>2;i--){
            group *=i;
        }
        return group;
    }
};
```
