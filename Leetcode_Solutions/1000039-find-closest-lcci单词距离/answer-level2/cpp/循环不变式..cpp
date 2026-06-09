### 解题思路
此处撰写解题思路
从未想过能在线性时间内完成.
这里的循环不变式为:
	每次循环总保持此前已经遍历过的元素中已经求出子问题的最小值,也就是距离.
理解了这个概念就能保证此算法的正确性,
而其高效性也是显而易见的.

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) 
{
	int ch1=-1,ch2=-1,minn=1000000;
	for(int i=0;i<words.size();i++)
	{
		if(words[i]==word1) {
			ch1=i;
			if(ch1!=-1&&ch2!=-1) minn=min(minn,abs(ch2-ch1));
		}
		else if(words[i]==word2)
		{
			ch2=i;
			if(ch1!=-1&&ch2!=-1) minn=min(minn,abs(ch2-ch1));
		}
	}
	return minn;	
}
};
```