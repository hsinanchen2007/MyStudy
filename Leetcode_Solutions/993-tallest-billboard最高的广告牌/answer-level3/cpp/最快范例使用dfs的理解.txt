```
class Solution {
private:
    int maxheight;
public:
    int tallestBillboard(vector<int>& rods) {
        if(rods.size() < 2){
            return 0;
        }
        int sum = 0;
        for(auto &i : rods){
            sum += i;
        }
        maxheight = 0;
        //从大到小排序,这样这样24行支剪就会尽快发生,否则超时
        sort(rods.begin(), rods.end(), greater<int>());
        //左右都一样，不妨就从左开始，省略向右的
        dfs(rods, 0, rods[0], 0, sum - rods[0]);
        dfs(rods, 0, 0, 0, sum - rods[0]);
        return maxheight;
    }

    void dfs(vector<int> &rods, int index, int left, int right, int remain){
        //剪去剩下的不足以使得左右对齐分支和对齐发生后不再增加左右高度38行的分支
        if(abs(left - right) > remain || left + right + remain <= maxheight * 2){
            return;
        }
        if(left == right){
            maxheight = max(maxheight, left);
        }
        //这里先增加index后判断边界,于是首次index参数为0
        index++;
        if(index == rods.size()){
            return;
        }
        remain -= rods[index];
        dfs(rods, index, left + rods[index], right, remain);
        dfs(rods, index, left, right + rods[index], remain);
        dfs(rods, index, left, right, remain);
    }
};
```
