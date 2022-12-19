class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
       map<string,int>q;
       vector<string>p;
       for(int i=0;i<list1.size();i++){
        q[list1[i]]=i;
       }
       int temp=INT_MAX;
        for(int i=0;i<list2.size();i++){
            if(q.count(list2[i])!=0){
                if(p.size()==0){
                p.push_back(list2[i]);
                    temp=q[list2[i]]+i;
                }
                else{
                    if(temp>q[list2[i]]+i){
                        p.clear();
                        p.push_back(list2[i]);
                        temp=q[list2[i]]+i;
                    }
                    else{if(temp==q[list2[i]]+i){p.push_back(list2[i]);}}
                }
            }
        }
        return p;
    }
};