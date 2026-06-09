贪心算法：

```
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //只需要记录每一个数字出现的次数就可以了，我们需要删除至少一半的数字，留下的数据小于一半
        int n=arr.size();
        vector<int>cnt;//记录每一个数字出现的次数
        int tmp=0;
        sort(arr.begin(),arr.end());//先对arr进行排序，否则不行的。。。
        for(int i=0;i<n;i++){//统计每一个数字出现的次数
            tmp++;
            if(i+1==n||arr[i]!=arr[i+1]){//某个重复数据统计结束
                cnt.push_back(tmp);
                tmp=0;
            }
        }
        sort(cnt.begin(),cnt.end(),greater<int>());
        int m=cnt.size();
        int ans=0,res=0;
        for(int i=0;i<m;i++){
            res+=cnt[i];
            ans++;
            if(res*2>=n){
                return ans;
            }
        }
        return 1;

    }
};
```
