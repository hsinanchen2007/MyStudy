### 解题思路
两次for循环判断，while循环中删除相同变量
	it = nums.erase(it);这个赋值比较重要否则在iterator中循环出问题
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int> &nums) 
{
	vector<int> ::iterator it;
	vector<int> ::iterator itNow;
	//vector<vector<int> ::iterator> m_vRecord;
	bool bIsFlag =false;
    //增加空值判断
    if(nums.size() <= 0)
	return nums.size();

	for (itNow = nums.begin() ; itNow != nums.end() - 1 ; itNow++ )
	{
		for (it = itNow + 1; it != nums.end() ; it++  )
		{
			while( *it == *itNow )
			{
				//这个it = 太重要了
				it = nums.erase(it);
				//需要判断是最后一项
				if(it == nums.end())
				{
					bIsFlag = true;
					break;
				}
			}	
			break;
		}
		if(bIsFlag)
			break;

	}
	return nums.size();
}
};
```