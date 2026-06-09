# 39. 组合总和
**思路：**

1. 方式利用数据结构set存储数组中candidates的所有记录值。
2. 编写递归函数 传入每层的值
    - 如果set中相减为0说明是一条成功路径，保存到结果二维数组中；
    - 如果相减大于0，说明还需要进行递归操作；
    - 如果相减小于0，不操作。
3. 这里需要剔除相同结果，所以迭代器不能回溯。
```
class Solution {
private:
	vector<vector<int>> rst;
	vector<int> temp;
	set<int> m_set;
public:
	void findRst(set<int>::iterator iter,int target){
		for( ; iter!=m_set.end(); ++iter){
			int diff = target-*iter;
			if( diff == 0 ){
				temp.push_back(*iter);
				rst.push_back(temp);
				temp.pop_back();
			}else if( diff > 0 ){
				temp.push_back(*iter);
				findRst(iter,diff);
				temp.pop_back();
			}
		}
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //遍历数组放入set 
        for( int i = 0; i < candidates.size(); ++i){
        	m_set.insert(candidates[i]);
        }

        set<int>::iterator iter = m_set.begin();
        findRst(iter,target);
        return rst;
    }
};
```
