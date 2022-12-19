`class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        
        // 找规律就能发现，一个分支就解决了
        // if(n == 1)
        //     return 1.0;
        // else
        //     return 0.5;
        
        // 定义一个动规数组
        vector<float> result;
        
        // 定义两个变量
        // 这个变量用于求第 i 个元素
        float temp = 0.0;
        // 这个变量用于求前 i-1 个元素的和
        float sum = 0.0;
        // 先把第一个元素压进去
        result.push_back(1.0);
        
        for(int i = 1; i < n; i++){
            // 第 1 个人有 i+1 种坐法，每种有 1/(i+1) 的可能性
            // 把前 i 项每一项都乘以 1/(i+1) 再累加，就是第 i+1 项的值
            sum += result[i - 1];
            temp = sum / (i + 1);
            result.push_back(temp);
        }
        // 然后我们就会发现，第一项是 1.0，后面全是 0.5
        return result.back();
    }
};`