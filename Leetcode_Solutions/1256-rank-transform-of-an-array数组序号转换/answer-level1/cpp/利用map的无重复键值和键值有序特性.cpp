比如      
        arr=[40,10,20,30,30]
那么 将arr插入到map中(value初始化为0)
在map中其形式了 
        <10,0>,<20,0>,<30,0>,<40,0>;
在按顺序从1开始递增赋值
        <10,1>,<20,2>,<30,3>,<40,4>;
再在arr中按元素顺序查找即可
代码为：
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
	    map<int, int>  m;
	    for (auto j : arr)
		    m[j]=0;
	    auto iter = m.begin(); auto end = m.end();
	    for (int i = 1; iter != end; i++, iter++)
		     iter->second = i;
	    vector<int>  res;
	    for (auto k : arr)
		    res.push_back(m[k]);
	    return res;
    }
};