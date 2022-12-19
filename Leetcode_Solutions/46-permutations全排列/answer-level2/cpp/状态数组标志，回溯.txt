### 解题思路
此处撰写解题思路

### 代码

```cpp
//借鉴题解里的一位大神的：可以使用“状态数组”来表明哪个每次遍历时用过的。
class Solution {
    vector<vector<int>>vec;  
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<int>path;
        vector<int>situation(nums.size(), 0);//注意3：用的是vector数组表状态
        backtrack(nums,path,0,situation);
        return vec;
    } 
    void backtrack(vector<int>& nums,vector<int>path,int count,vector<int>& situation){
        if(nums.size()==count) {
            vec.push_back(path);
            return; 
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(!situation[i]){  //注意1：循环找没有过使用状态
                    path.push_back(nums[i]);
                    situation[i]=1;  //1表示  ：将该状态标位已使用
                    backtrack(nums,path,count+1,situation);//注意1：++count换成count+1才有用:是因为当你在某一层向下枝递归时，count的值变了，回溯时，count的值就会与这一层本该的值不同
                    situation[i]=0; //0表示：删除已使用的标志，可以再次使用
                    path.pop_back();
                }                        
            }
        }
    }
};
```