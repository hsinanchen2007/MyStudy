class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        string str1=A[0];
        for(auto j=0;j<str1.length();j++){
            string str2(1, str1[j]);
            //cout<<str2<<endl;
            bool flag = true;
            for(auto i=1;i<A.size();i++){
                int pos = A[i].find(str2);
                if(pos == string::npos){
                    flag = false;
                    break;
                } else {
                    A[i].erase(pos, 1);
                }
            }
            if(flag) res.push_back(str2);
        }
        return res;
    }
};