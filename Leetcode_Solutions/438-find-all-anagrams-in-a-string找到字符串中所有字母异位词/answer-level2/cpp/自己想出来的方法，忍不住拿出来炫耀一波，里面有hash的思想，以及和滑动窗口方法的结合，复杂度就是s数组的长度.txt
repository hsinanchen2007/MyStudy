class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int length1=s.size(),length2=p.size(),numbers[26];
        vector<int> back1;
        if(length1>=length2){
            memset(numbers,0,sizeof(numbers));
            for(int i=0;i<length2;i++){
                numbers[p[i]-'a']++;
            }
            int k=0,l=0;
            while(k<=(length1-length2)){
                for(;l-k<length2;l++){
                    numbers[s[l]-'a']--;
                    if(numbers[s[l]-'a']<0){
                        numbers[s[l]-'a']++;
                        break;
                    }
                }
                if(l-k==length2){
                    back1.push_back(k);
                }
                numbers[s[k]-'a']++;
                k++;
            }
        }        
        return back1;
    }
};