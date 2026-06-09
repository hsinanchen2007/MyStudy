```
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<=1) return chars.size();
        int num=1,pos=0;
        for(int i=0;i<chars.size()-1;++i){
            if(chars[i]==chars[i+1]){
                num++;
            }else{
                string temp=to_string(num);
                chars[pos++]=chars[i];
                if(num>1){
                    for(int j=0;j<temp.length();++j){
                        chars[pos++]=temp[j];
                    }
                }
                num=1;
            }
        }
        if(num>1){
            string temp=to_string(num);
            chars[pos++]=chars[chars.size()-1];
            for(int j=0;j<temp.length();++j){
                chars[pos++]=temp[j];
            }
        }else chars[pos++]=chars[chars.size()-1];
        int more=chars.size()-pos;
        while(more>0){
            chars.pop_back();
            more--;
        }
        return pos;
    }
};
```
