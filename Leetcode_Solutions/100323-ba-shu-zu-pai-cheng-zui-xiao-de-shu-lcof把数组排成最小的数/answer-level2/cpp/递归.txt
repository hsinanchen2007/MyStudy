    class Solution {
    public:
        bool isGreater(string& a, string& b){
            string ab = a+b;
            string ba = b+a;
            int n = ab.size();
            for(int i = 0; i < n; ++i){
                if(ab[i] > ba[i])return true;
                else if(ab[i] < ba[i])return false;
            }
            return false;
        }
        string minNumber(vector<int>& nums) {
            vector<string> v;
            v.push_back(to_string(nums[0]));
            int n = nums.size();
            for(int i = 1; i < n; ++i){
                string s = to_string(nums[i]);
                int j = 0;
                int m = v.size();
                while(j<m && isGreater(s,v[j]))++j;
                v.insert(v.begin()+j,s);
            }
            string ret;
            for(string str:v)ret += str;
            return ret;
        }
    };