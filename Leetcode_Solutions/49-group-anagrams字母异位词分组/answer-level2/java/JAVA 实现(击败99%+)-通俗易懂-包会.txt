![image.png](https://pic.leetcode-cn.com/769aeeff05dd83b4fd2b6afe7dcc2c17032ed3be6e63a79d4935317ee918f59c-image.png)

```
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
    	List<List<String>>  arrResList = new ArrayList<>();
    	if (strs == null || strs.length ==0) {
			return arrResList;
		}
    	if (strs.length ==1) {
    		List<String> newList = new ArrayList<>();
    		newList.add(strs[0]);
    		arrResList.add(newList);
    		return arrResList;
    		
		}
    	//保存已出现过的单词(key->单词排序后端字符串;value->单词整结果集中的索引)
    	Map<String, Integer> map = new HashMap<String, Integer>();
    	String str = "";
    	int  index = 0,tindex = 0;
    	List<String> rList;
    	for(int i = 0;i<strs.length;i++){
    		str = pareString(strs[i]);
    		if (map.containsKey(str)) {
    			tindex  = map.get(str);
    			arrResList.get(tindex).add(strs[i]);
			}else{
				//第一次遇到次单词，直接加到结果集
				rList = new ArrayList<>();
				rList.add(strs[i]);
				arrResList.add(rList);
				map.put(str, index);
				index ++;
			}
    	}
    	
    	return arrResList;
    }
    public  String pareString(String str){
    	char[] arrChar = str.toCharArray();
    	Arrays.sort(arrChar);
    	return new String(arrChar);
    }
}
```
