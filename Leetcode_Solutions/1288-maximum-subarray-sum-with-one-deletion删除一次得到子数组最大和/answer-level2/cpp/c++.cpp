```
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int size=arr.size();
        if(size<=0)return 0;
        vector<int> v_val(size,0),v_status(size,0),v_max(size,0);
        //0代表没有删除过元素，1代表删除过1次元素
        v_val[0]=arr[0],v_status[0]=0,v_max[0]=arr[0];
        for(int i=1;i<size;++i){
            v_max[i]=v_max[i-1]<0?arr[i]:v_max[i-1]+arr[i];
            if(arr[i]>=0){
                if(v_val[i-1]>0){
                    v_val[i]=v_val[i-1]+arr[i];
                    v_status[i]=v_status[i-1];
                }
                else if(v_val[i-1]<=0){
                    v_val[i]=arr[i];
                    v_status[i]=0;
                }
            }
            else{
                if(v_status[i-1]==0){
                    v_val[i]=v_val[i-1];
                    v_status[i]=1;
                }
                else{
                    v_val[i]=max(v_max[i-1],v_val[i-1]+arr[i]);
                    v_status[i]=1;  
                }              
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<size;++i){
            ans=max(ans,v_val[i]);
            //cout<<i<<"       "<<v_val[i]<<endl;
        }
        return ans;
    }
};
```
