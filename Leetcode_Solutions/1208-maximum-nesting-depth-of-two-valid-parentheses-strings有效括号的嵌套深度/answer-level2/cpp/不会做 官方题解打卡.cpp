### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {	
		vector<int>arr(seq.length());
		int size=0;		
		for(int i=0;i<seq.length();i++)
		{
			if(seq[i]=='(')
			{
				size++;
				arr[i]=size%2;
			}
			else
			{
				arr[i]=size%2;
				size--;				
			}
		}
		return arr; 
    }
};
```