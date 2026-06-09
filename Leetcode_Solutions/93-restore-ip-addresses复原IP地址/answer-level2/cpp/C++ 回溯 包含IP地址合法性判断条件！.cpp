首先对IP地址的限制条件进行分析：
> 对IP合法性要求：
1. ip格式每个部分占8位，最大不能超过255；
2. 每段位数在1-3之间（在取前面段的时候要判断剩余位数是否能满足后面的最大/最小位数要求）；
3. 一共4段，代表树最多有4层；
4. 当每段长度>1时，第一位不能是'0'；
#### 上代码！
```
class Solution {
public:
    vector<string>res;
    int n; //字符串s长度
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        dfs(0, 0, "", s);
        return res;
    }
    /*
    * @param start:当前开始的位置
    * @param depth: 当前选出了几个段
    * @param path: 传递的路径(一般字符串问题都将路径作为传递，可以解决回溯弹出问题)
    * @param s:给出的需要分割的字符串
    */
    void dfs(int start, int depth, string path, string s) {
        if(depth == 4) {
            path.pop_back(); //除去传递参数时最后一次多加的'.'
            res.push_back(path);
            return;
        }
        //endMin 表示最短可以在哪里结束, endMax 表示最长可以在哪里结束
        // 3 - depth 表示剩余的 ip 段个数 (EG.当depth=0,现在正在处理第一段,还剩3段)
        // n - (3 - depth) * 3 表示剩余的 ip 段如果都是 3 位数，当前 ip 段的结束位置（取不到）
        // start + 1 也是因为取不到
        int endMin = max(start + 1, n - (3 - depth) * 3);
        // n - (3 - depth) * 1 表示剩余的 ip 段如果都是 1 位数，当前 ip 段的结束位置（取不到）
        int endMax = min(start + 3, n - (3 - depth));

        for(int end = endMin; end <= endMax; end++) {
            string split = s.substr(start, end - start); // end - start 表示截取长度
            int splitLen = split.size();
            if(splitLen > 1 && split[0] == '0') { //当长度>1时, 第一位不能为0
                break;
            }
            if(stoi(split) <= 255) { //转换为int判断
                dfs(end, depth + 1, path + (split + '.'), s);
            }
        }
    }
};
```