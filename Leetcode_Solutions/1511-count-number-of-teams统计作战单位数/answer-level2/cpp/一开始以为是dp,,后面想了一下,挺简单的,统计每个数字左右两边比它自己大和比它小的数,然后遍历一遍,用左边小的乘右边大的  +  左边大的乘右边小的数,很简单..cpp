### 解题思路
此处撰写解题思路

### 代码

```cpp
struct node{
    int value;
    int lmax=0;
    int lmin=0;
    int rmax=0;
    int rmin=0;
};
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        struct node a[n];
        for(int i=0;i<n;i++){
            a[i].value = rating[i];
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(a[j].value<a[i].value){
                    a[i].lmin++;
                }
                else if(a[j].value>a[i].value){
                    a[i].lmax++;
                }
            }
            for(int j = i+1;j<n;j++){
                if(a[j].value<a[i].value){
                    a[i].rmin++;
                }
                else if(a[j].value>a[i].value){
                    a[i].rmax++;
                }
            }
        }
        int ret = 0;
        for(int i =1;i<n-1;i++){
            ret+=(a[i].lmax*a[i].rmin);
            ret+=(a[i].lmin*a[i].rmax);
        }
        for(int i =0;i<n;i++){
            cout<<a[i].value<<" "<<a[i].lmin<<" "<<a[i].lmax<<" "<<a[i].rmin<<" "<<a[i].rmax<<endl;
        }
        return ret;
    }
};
```