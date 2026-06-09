第一次尝试视频，自己也比较菜，声音也难听，视频很粗糙，见笑了。
![...51.mpeg4.aac (1).mp4](dd925b56-7441-4c00-9309-aeb13ec4a6f1)
```

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<1) return res;
        backtrack("",n,n,res);
        return res;
    }
    void backtrack(string curStr,int left,int right,vector<string>& res){
        if(left==0 && right==0){
            res.push_back(curStr);
            return ;
        }
        if(left>0){
            //left--; 注意一定不能这么写，如果这么写的话，后面还要写left++，否则递归回来的时候，已经不是当时的现场了。
            backtrack(curStr+"(",left-1,right,res);
        }
        if(right>left){
            backtrack(curStr+")",left,right-1,res);
        }
    }
};
```
