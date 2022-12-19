

### 代码

```cpp
class Solution {
public:
    int findIntegers(int num) {
        vector<int> bp={0,1,3};
        vector<int> v;
        int ans=num+1;
        while(num!=0){
            v.push_back(num%2);
            num=num/2;
        }
        int temp=2;
        while(bp.size()<=v.size()){
            int size=bp.size();
            bp.push_back(bp[size-1]+bp[size-2]+pow(2,temp));
            ++temp;
        }
        for(int i=v.size()-1;i>=0;--i){
            if(v[i]==1){
                if(i-1>=0)ans-=bp[i-1];
            }
            if(i+1<v.size()&&v[i]==1&&v[i+1]==1){
                int temp=0;
                for(int j=i-1;j>=0;--j){
                    temp=temp*2+v[j];
                }
                ans-=(temp+1);
                break;
            }

        }
        return ans;
    }
};
```