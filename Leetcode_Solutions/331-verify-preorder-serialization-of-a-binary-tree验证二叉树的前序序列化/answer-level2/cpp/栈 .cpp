模拟先序遍历
```c++
class Solution {
public:
    vector<string> s;
    bool isValidSerialization(string preorder) {
        int n = preorder.size(),i=0,k=0;
        if(n==1&&preorder!="#")return false;
        while(i<n){
            if(preorder[i]==',')i++;
            int j=i;
            while(i<n&&preorder[i]!=',')i++;
            s.push_back(preorder.substr(j,i-j)),k++;
            while(k>=3&&s[k-1]=="#"&&s[k-2]=="#"){
                s.pop_back();
                s.pop_back();
                k-=2;
                if(s[k-1]=="#")return false;
                s.pop_back();
                s.push_back("#");
            }
        }
        return s.size() == 1;
    }
};
```