```
class Solution {
public://执行用时 :4 ms, 在所有 C++ 提交中击败了86.49%的用户
    int len;
    string s;
    double res = INT_MIN;
    vector<int> path,rec;
    double prediv[10][10];
    string optimalDivision(vector<int>& nums) {
        len = nums.size();
        for(int i=0;i<len;i++) { //预处理区间结果
            prediv[i][i] = nums[i];
            for(int j=i+1;j<len;j++) prediv[i][j] = prediv[i][j-1] / nums[j];
        }
        dfs(0,0);
        for(int i=0;i<rec.size();i+=2) { //根据rec中的元素依次两两配对来生成字符串
            if(i) s.push_back('/');
            if(rec[i]==rec[i+1]) s+=trans(nums[rec[i]]);//数字转字符串不多说了自行百度
            else {
                s.push_back('(');
                for(int j=rec[i];j<=rec[i+1];j++) {
                    if(j!=rec[i]) s.push_back('/');
                    s+=trans(nums[j]);
                }
                s.push_back(')');
            }
        }
        return s;
    }
    void dfs(int start,double sum) {
        if(start==len) {//终点记录结果
            if(sum>res) res = sum,rec = path;
            return;
        }
        path.push_back(start);
        for(int i=start;i<len;i++) {
            path.push_back(i);
            if(start) dfs(i+1,sum/prediv[start][i]);
            else dfs(i+1,prediv[start][i]);
            path.pop_back();
        }
        path.pop_back();
    }
};
```
