```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        auto a=height.begin();
        auto b=height.end()-1;
        int max=0;
        while(a!=b){
            max=max>(min(*a,*b)*(j-i))?max:(min(*a,*b)*(j-i));
            if(*a>*b){
                j--;
                b--;
            }
            else{
                i++;
                a++;
            }
        }
        return max;
    }
};
```
