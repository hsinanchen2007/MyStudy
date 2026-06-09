### 解题思路
第一次写回溯法，用自己的理解写的，跟标准的差不多，不懂原理的可以去看一下图解。

### 代码

```cpp
class Solution {
private:
    vector<int> path,n;
    vector<vector<int>> res;
public:
    void cal(){
        if(path.size()==n.size()){
            res.push_back(path);    //添加到结集
            return;
        }
        for(int i=0;i<n.size();i++){
            vector<int>::iterator exist = find(path.begin(),path.end(),n[i]);   //查找这个元素是否已经用过
            if(exist!=path.end()){  //元素存在
                continue;
            }
            path.push_back(n[i]);   //添加元素
            cal();                  //进入下一层
            path.pop_back();        //删除元素
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums;
        cal();
        return res;
    }
};
```