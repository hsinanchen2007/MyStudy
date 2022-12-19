```
class Solution {
public:
    // 双指针 reverse
    void my_reverse(string&s, int l,int r){
        while(l<r){
            char tmp = s[r];
            s[r] = s[l];
            s[l] = tmp;
            l++;r--;
        }
    }
    /*
        提问 开头有无空格。
    */
    string reverseWords(string s) {
        int len = s.length();
       // stack<char>st;
        int l = 0;
        for(int i=0;i<=len;i++){
            if(i == len){
                my_reverse(s,l,i-1);
                // while(l < len && st.size()) {
                //     s[l++] = st.top();st.pop();
                // }
            }else{
                if(s[i] == ' '){
                    my_reverse(s,l,i-1);
                    l = i+1;
                    // while(st.size()) {
                    //     s[l++] = st.top();st.pop();
                    // }
                    // l++;
                }
            }
        }

        return s;
    }
};
```
