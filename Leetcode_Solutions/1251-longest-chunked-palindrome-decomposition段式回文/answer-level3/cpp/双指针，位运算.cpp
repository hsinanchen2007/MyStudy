```
class Solution {
public:
    int longestDecomposition(string text) {
        int left=0,right=text.size()-1;
        int last_left=left,last_right=right;
        int count=0;
        int lvalue=0,rvalue=0;
        while(left<right){
            lvalue=lvalue^(1<<(text[left]-'a'));
            rvalue=rvalue^(1<<(text[right]-'a'));
            if(lvalue==rvalue&&text.substr(last_left,left-last_left+1)==text.substr(right,last_right-right+1)){
                count+=2;
                lvalue=0;
                rvalue=0;
                last_left=left+1;
                last_right=right-1;
            }
            ++left;
            --right;
        }
        if(last_left<=last_right){
            ++count;
        }
        return count;
    }
};
```
