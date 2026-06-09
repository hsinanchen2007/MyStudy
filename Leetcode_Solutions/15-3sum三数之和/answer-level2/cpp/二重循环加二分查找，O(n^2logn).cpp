```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int i,j,k,g,h,n=a.size();
        vector<vector<int>>ans;
        vector<int>t(3);
        sort(a.begin(),a.end());
        for(i=0;i+2<n;i++){
            for(j=i+1;j+1<n;j++){
                g=-a[i]-a[j];
                k=lower_bound(a.begin()+j+1,a.end(),g)-a.begin();
                if(k<n&&a[k]==g){
                    t[0]=a[i];t[1]=a[j];t[2]=a[k];
                    ans.push_back(t);//符合条件，加入
                }
                h=a[j];while(j<n&&a[j]==h){j++;}
                j--;//去重 
            }
            h=a[i];while(i<n&&a[i]==h)i++;
            i--;//去重
        }
        return ans;
    }
};
```
