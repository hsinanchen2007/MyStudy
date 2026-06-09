### 解题思路
此处撰写解题思路
根据官方思路做的，不过自己之前做的过程可以说一下：

二分法确认最长重复子字符串是必须的。参考官方说明。
1.第一步，在检查子字符串是否重复时，是取下子字符串放在一个Set中。结果内存超过限制。
2.考虑到int类型内存更小，采取将子字符串调用jdk自身的hashcode()方法获取hash值保存在集合中
   结果超时。
3.既然超时，那就要解决超时问题，就到了官方解决方案中的自行计算hash值得问题。参考官方解答将计算好hash值
  保存到集合中，结果出现hash碰撞，存在不同子字符串hashhash值一样，查找失败
4.此时，将hash值和子字符串起始位置存入hashMap中，hash值一样的时候，去比较字符串是否equal。
到此，解决了问题

### 代码

```java
class Solution {

    public boolean findSame(Set<Integer>set, int index, int subLen, String s)
	{
		for(int i : set)
		{
			if(s.regionMatches(i, s, index, subLen))
			{
				return true;
			}
		}
		set.add(index);
		return false;
	}
	
    public int checkSubExists(String s, int subLen, Map<Long, Set<Integer>> map)
	{
		Long base = 26l;
		Long hash0 = (long)(s.charAt(0) - 'a');
		Long model = (long)Integer.MAX_VALUE;
		
		for(int i = 1; i < subLen; i++)
		{
			base = (26 * base) % model;
			hash0 = (hash0 * 26 + (s.charAt(i) - 'a')) % model ; 
		}
		Set<Integer> set = new HashSet<Integer>();
		set.add(0);
		map.put(hash0, set);
		
		for(int i = 1; i < s.length() - subLen + 1; i++)
		{
			hash0 = (hash0 * 26 - (s.charAt(i - 1) - 'a') * base % model + model) % model;
			hash0 = (hash0 + (s.charAt(i + subLen -1) - 'a')) % model;
						
			if(map.containsKey(hash0))
			{
				
				if(findSame(map.get(hash0), i, subLen, s))
				{
					return i;
				}
			} else {
				set = new HashSet<Integer>();
				set.add(i);
				map.put(hash0, set);
			}
		}
		return -1;
	}

	public String longestDupSubstring(String s)
	{
		//当前用KMP的next将会超时，需要进一步优化
		int len = s.length();
		int max = 0;
		int startIndex = 0;
		Map<Long, Set<Integer>> map = new HashMap<Long, Set<Integer>>();
		
		int left = 1;
		int right = len;
		int tmpIndex = -1;
        //String last = "";
		//String tmpStr = null;
        Set<Integer> setLen = new HashSet<Integer>();
		int subLen = 0;
		while(left < right)
		{
			map.clear();
			subLen = (left + right) / 2;
			if (!setLen.add(subLen)) 
			{
				break;
			}
					
			tmpIndex = this.checkSubExists(s, subLen, map);
			if(tmpIndex == -1)
			{
				right = subLen;
			}
			else
			{
				left = subLen;
				if(subLen > max)
				{
					startIndex = tmpIndex;
                    max = subLen;
				}
			}
		}
		
		//return last;
		return s.substring(startIndex, startIndex + max);
	}
}
```