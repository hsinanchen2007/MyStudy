法一：　前缀求和　暴力
```
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> sum(hours.size(),0);
        int i,j;
        if(hours[0]>8){
            sum[0]=1;hours[0]=1;
        } 
        else{
            sum[0]=-1;hours[0]=-1;
        } 
        for(i=1;i<hours.size();i++){
            if(hours[i]>8){
                sum[i]+=sum[i-1]+1;
                hours[i]=1;
            } 
            else{
                sum[i]+=sum[i-1]-1;
                hours[i]=-1;
            } 
        }
        int len=0;
        for(i=0;i<hours.size();i++){
            for(j=hours.size()-1;j-i+1>len&&j>=0;j--){
                if(sum[j]-sum[i]+hours[i]>0&&j-i+1>len){
                    len=j-i+1;
                    break;
                }
            }
        }
        return len;
    }
};
```
法二：单调栈：　（借鉴楼上）
```
class Solution {
public:
    int longestWPI(vector<int>& hours) {
　　　　　vector<int> sum(hours.size()+1,0);
        sum[0]=0;
        for(int i=1;i<sum.size();i++){
            sum[i]+=sum[i-1]+(hours[i-1]>8?1:-1);
        }
        stack<int> st;//单调递减栈
        for(int i=0;i<sum.size();i++){
            if(!st.empty()&&sum[st.top()]<=sum[i])continue;
            st.push(i);
        }
        int ans=0;
        for(int i=sum.size()-1;i>=0;i--){
            if(sum[i]>sum[st.top()]){
                ans=max(ans,i-st.top());
                st.pop();i++;
                if(st.size()==0) break;
            }
        }
        return ans;
    }
```

