class Solution {
public:
    string decodeString(string s) {
        vector<char> data;
        vector<int> times;
        int len;
        string result="";
        
        len=s.size();
        for(int i=0;i<len;i++){
            string str="";
            char tmp;
            int number;
            
            tmp=s[i];
            if(tmp<'9'&&tmp>'0'){
                int j=i;
                for(;s[j]!='[';j++){
                    str+=s[j];
                }
                i=j-1;
                times.push_back(atoi(str.c_str()));
            }else if(tmp==']'){
                string backup="";
                int string_size;
                while(data.back()!='['){
                    str+=data.back();
                    data.pop_back();
                }
                reverse(str.begin(),str.end());
                data.pop_back();
                number=times.back();
                times.pop_back();
                
                backup=str;
                for(int i=0;i<number-1;i++){
                    str=str+backup;
                }
                string_size=str.size();
                for(int i=0;i<string_size;i++){
                    data.push_back(str[i]);
                }
            }else{
                data.push_back(s[i]);
            }
        }
        len=data.size();
        for(int i=0;i<len;i++){
            result+=data[i];
        }
        return result;
    }
};