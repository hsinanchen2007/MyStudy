class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int last=S.find(C);
        int l=S.size();
        vector<int> res;
        for(int i=0;i<S.size();i++){
            if(S[i]==C){
                res.push_back(0);
                last=i;
            }
            else {
			string temp = S.substr(i, l - 1);
			int d = temp.find(C);
			if (d != -1)
				res.push_back(min(abs(i - last), d));
			else
				res.push_back(abs(i - last));
		}
           
        }
        return res;
    }
};
题解的复杂度比较高，期待各位大神给出优化意见