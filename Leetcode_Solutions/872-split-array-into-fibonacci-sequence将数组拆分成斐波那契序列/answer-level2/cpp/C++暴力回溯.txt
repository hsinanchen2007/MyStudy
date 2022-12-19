方法就是暴力回溯，注意的点就是可能会超过int的最大值
看了下冬瓜的解答，他提到一个剪枝的点是前两个数有一个是小于等于len/3+1。这个规律推广一下就是：假设已经有了n个数满足条件，那么下一个数的最大值就是占领后面所有的字符。这样就是把字符串分隔成n+1份。但是如果最后一个数即便占领了最后的所有字符，但它的长度仍然小于 len/(n+1)的话，那么是不满足斐波那契数列递增规律的。所有可以进行剪枝。转换为代码的话，可以判断start的位置是否超过了某个阈值，具体见代码。


```
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        bool result = doSubFibonacci(S, 0, -1, -1, res);
        if (result) {
            return res;
        } else {
            return {};
        }
    }
    
    bool doSubFibonacci(string s, int start, int val1, int val2, vector<int> &res) {
        int size = res.size();
        if (start == s.length() && size >= 3) {
            return true;
        }
        long long targetVal = (long long)val1 + val2;
        
        if (targetVal > INT_MAX || start > s.length() * size / max(size +1 ,3) +1) {// 这里可以进行strat的剪枝
                return false;
        }
        for (int i = 1; i < s.length() - start + 1; i++) {
            string subStr = s.substr(start, i);
            long long val = stoll(subStr);
            if (val > INT_MAX) {
                return false;
            }
            if (subStr.length() > 1 && val < 10) {
                return false;
            }
            if (val1 == -1 || val2 == -1 || val == targetVal) {
                res.push_back((int)val);
                bool result = doSubFibonacci(s, start + i, val2, (int)val, res);
                if (!result) {
                    res.pop_back();
                } else {
                    return true;
                }
            } else if (val > val1 + val2) {
                return false;
            }
        }
        return false;
    }
};
```