#  40. 组合总和 II（C++ 递归回溯）
与上一题的区别为由于每条数据只能用一次，而且数据可能重复，所以使用map数据结果存储数据。
利用数据结构map<int,int>：
- 第一个值存储数组中candidates的所有记录值；
- 由于map不支持重复映射的存储，所以我们用第二个值存储映射出现的次数。

编写递归函数 我们进行遍历时要注意该数据是否被用完，每次使用后次map对应值减一，再进行操作判断，注意，回溯需要恢复现场，即:
```
iter->second = iter->second + 1;
temp.pop_back();
```
这两步操作！

**注意:这里需要剔除相同结果，所以迭代器不能回溯。**
```
class Solution {
private:
	vector<vector<int>> rst;
	vector<int> temp;
	map<int,int> m_map;
public:
	void findRst(map<int,int>::iterator iter,int target){
		for( ; iter!=m_map.end(); ++iter){
			if( iter->second > 0 ){
				int diff = target-iter->first;
				if( diff == 0 ){
					temp.push_back(iter->first);
					iter->second = iter->second - 1;
					rst.push_back(temp);
					//恢复现场
					iter->second = iter->second + 1;
					temp.pop_back();
				}else if( diff > 0 ){
					temp.push_back(iter->first);
					iter->second = iter->second - 1;
					findRst(iter,diff);
					//恢复现场
					iter->second = iter->second + 1;
					temp.pop_back();
				}
			}
		}
	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int>::iterator iter;
        for( int i = 0; i < candidates.size(); ++i){
        	if( (iter=m_map.find(candidates[i])) != m_map.end() ){
        		iter->second = iter->second + 1;
        	}else{
        		m_map.insert(pair<int,int>(candidates[i],1));
        	}
        }
        iter = m_map.begin();
        findRst(iter,target);
        return rst;
    }
};
```
