```
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int ans=1;
        set<int> s;
        queue<int> q;
        int temp=0;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j){
                temp=temp*10+board[i][j];
            }
        }
        if(temp==123450)return 0;
        q.push(temp);
        s.insert(temp);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                temp=q.front();
                q.pop();
                vector<int> v=next(temp);
                for(auto a:v){
                    if(a==123450){
                        return ans;
                    }
                    if(!s.count(a)){
                        s.insert(a);
                        q.push(a);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }

    vector<int> next(int temp){
        vector<int> ans;
        if(temp%10==0){
            ans.push_back(transform(temp,0,1));
            ans.push_back(transform(temp,0,3));
        }
        else if((temp/10)%10==0){
            ans.push_back(transform(temp,1,0));
            ans.push_back(transform(temp,1,2));
            ans.push_back(transform(temp,1,4));
        }
        else if((temp/100)%10==0){
            ans.push_back(transform(temp,2,1));
            ans.push_back(transform(temp,2,5));
        }
        else if((temp/1000)%10==0){
            ans.push_back(transform(temp,3,0));
            ans.push_back(transform(temp,3,4));
        }
        else if((temp/10000)%10==0){
            ans.push_back(transform(temp,4,3));
            ans.push_back(transform(temp,4,1));
            ans.push_back(transform(temp,4,5));
        }
        else{
            ans.push_back(transform(temp,5,4));
            ans.push_back(transform(temp,5,2));
        }
        return ans;
    }
    int transform(int temp,int first,int second){
        //cout<<temp<<" "<<first<<" "<<second<<endl;
        int first_value=temp/(int)pow(10,first)%10;
        int second_value=temp/(int)pow(10,second)%10;
        temp=temp+pow(10,first)*(second_value-first_value)+pow(10,second)*(first_value-second_value);
        //cout<<temp<<endl;
        return temp;
    }
};
```
