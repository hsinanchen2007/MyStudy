
![image.png](https://pic.leetcode-cn.com/0ad795c1230c95c0c3baddd32ee7c64daed1d15f904edec11250dfa60eb28b42-image.png)

### 代码

```java
class Solution {
	public int longestStrChain(String[] words) {
        int maxlenth = 1;
        HashMap<Integer, ArrayList> m = new HashMap<Integer, ArrayList>();
        
        //先将所有字符按照长度来分组
        for(int i =0;i<words.length;i++) 
        {
        	if(m.get(words[i].length()) == null) 
        	{
        		m.put(words[i].length(),new ArrayList<String>());
        	}
        	
        	m.get(words[i].length()).add(words[i]);
        }
        
        //按照长度倒序来遍历,因为题目已经要求字符串长度最长为16,所以从16开始遍历
        for(int i=16;i>0;i--) 
        {
        	//如果当前遍历的字符长度已经比已知的最大长度要小,那么不用再遍历了
        	if(i <= maxlenth) 
        	{
        		break;
        	}
        	
        	ArrayList<String> currentList = m.get(i);
        	if(currentList == null) 
        	{
        		continue;
        	}
        	
        	//递归获取长度小一点的子字符串最大词链长度
        	for(int j=0;j<currentList.size();j++) 
        	{
        		String currentword = currentList.get(j);
        		int maxlenthTemp = 1 + getSubLenth(currentword,m);
        		if(maxlenthTemp > maxlenth) 
        		{
        			maxlenth = maxlenthTemp;
        		}
        	}
        }
    	
        return maxlenth;
    }

	private int getSubLenth(String word, HashMap<Integer, ArrayList> m) {
		int maxlenth = 0;
		char[] wordCharList = word.toCharArray();
		char[] currentWordCharList = null;
		int displacement=0;
			
        	ArrayList<String> currentList = m.get(word.length() - 1);
        	if(currentList == null) 
        	{
        		return maxlenth;
        	}
        	
        	for(int j=0;j<currentList.size();j++) 
        	{
        		boolean isSubString = true;

        		displacement = 0;
        		String currentword = currentList.get(j);
        		currentWordCharList = currentword.toCharArray();
        		
        		for(int i = 0;i< wordCharList.length;i++) 
        		{
        			if(displacement == 0 && i == currentWordCharList.length) 
        			{
        				break;
        			}
        			
        			if(wordCharList[i] != currentWordCharList[i - displacement]) 
        			{
        				displacement ++;
        			}
        			
        			if(displacement > 1) 
        			{
        				isSubString = false;
        				break;
        			}
        		}
        		
        		if(isSubString) 
        		{
        			int maxlenthTemp= 1 + getSubLenth(currentword,m);
        			if(maxlenthTemp > maxlenth) 
            		{
            			maxlenth = maxlenthTemp;
            		}
        		}
        	}
        
		return maxlenth;
	}
}
```