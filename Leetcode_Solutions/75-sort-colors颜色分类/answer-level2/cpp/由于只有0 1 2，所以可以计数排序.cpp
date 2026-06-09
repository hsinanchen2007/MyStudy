

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(!nums.size()) return;
        map<int,int>color;
        color[0]=0;
        color[1]=0;
        color[2]=0;
        for(auto i:nums)
          color[i]+=1;
        int n=0;
        nums.clear();
        while(n<=2){
          for(int j=0;j<color[n];j++)
            nums.push_back(n);
          n++;
        }
    }
};
```