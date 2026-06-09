```
class Solution {
public:
    bool rotateString(string A, string B) {
        multimap<char,char> mymap;
        for(int i=0;i<A.size();i++){
            int nextIndex = i + 1;
            if(nextIndex==A.size())nextIndex = 0;
            mymap.insert(make_pair(A[i],A[nextIndex]));
        }

        for(int i=0;i<B.size();i++){
            int nextIndex = i + 1;
            if(nextIndex==A.size())nextIndex = 0;
            
            multimap<char,char>::iterator it;
            it = mymap.find(B[i]);
            bool flag = false;
            for(int j=0;j<mymap.count(B[i]);j++,it++){
                //cout<<"B[i]:"<<B[i]<<"---B[nextIndex]:"<<B[nextIndex]<<"***"<<it->second<<endl;
                if(it->second == B[nextIndex]){
                    flag = true;
                    break;
                }
            }
            if(!flag)
                return false;
        }
        return true;
    }
};
```
