#### 解题思路：
- 注意众数的定义；
- 注意中位数的求法；


- 最小值：通过排序直接获取最小值即可，及 `count[i] > 0` 的最小的 `i` 值；
- 最大值：通过排序直接获取最大值即可，及 `count[i] > 0` 的最大的 `i` 值；
- 众位数：最大的 `count[i]` 所有的索引值 `i`；
- 平均值：统计所有的值，除以总的数目即可，注意累加溢出的问题，采用 `longlong` 类型记录和即可
- 中位数：如果 `count` 为偶数 则找到排名在 `count/2`、`count/2+1` 的 `index` 即可

#### 代码：
```c++ [-C++]
class Solution {
public:
    int findNth(vector<int> & count,int n){
        for(int i = 0; i < count.size(); ++i){
            n = n - count[i];
            if(n <= 0){
                return i;
            }
        }
        
        return 0;
    }
    
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;
        int n = count.size();
        long long sum = 0;
        int samples = 0;
        int maxCnt = 0;
        double minNum = 0.0;
        double maxNum = 0.0;
        double average = 0.0;
        double medium = 0.0;
        double mode = 0.0;
        
        for(int i = 0;i < n; ++i){
            sum += count[i]*i;
            if(count[i] > maxCnt){
                maxCnt = count[i];
                mode = i;
            }
            samples += count[i];
        }
        for(int i = 0;i < n; ++i){
            if(count[i] > 0){
                minNum = i;
                break;
            }
        }
        for(int i = n-1;i >= 0; --i){
            if(count[i] > 0){
                maxNum = i;
                break;
            }
        }
                
        if(samples%2 == 0){
            int l1 = findNth(count,samples/2);
            int l2 = findNth(count,samples/2+1);
            medium = double(l1+l2)/2;
        }else{
            int l1 = findNth(count,samples/2+1);
            medium = double(l1);
        }
        
        /*min*/
        ans.push_back(minNum);
        ans.push_back(maxNum);
        ans.push_back(double(sum)/samples);
        ans.push_back(medium);
        ans.push_back(mode);
            
        return ans;
    }
};
```
