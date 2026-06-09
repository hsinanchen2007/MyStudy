class Solution {
- public:
    bool checkInclusion(string s1, string s2) {
          int left=0;
          int right=0;
          int match=0;
         unordered_map<char,int>window;
         unordered_map<char,int>need;
         for(char i:s1){
             need[i]++;
         }
         while(right<s2.size()){
             char tmp=s2[right];
             if(need.count(tmp)){
                 window[tmp]++;
                 if(window[tmp]==need[tmp]){
                     match++;
                 }
             }
             right++;
         while(match==need.size()){
          if(right-left==s1.size()){
             return true;
         }
            char num=s2[left];
            if(need.count(num)){
                window[num]--;
                if(window[num]<need[num]){
                    match--;
                }
            }
            left++;
         }
         }
         return false;
    }
};