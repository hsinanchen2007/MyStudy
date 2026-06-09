# 标题 组合倒推法

*思想方法*

1、首先根据题目描述可知是一个排序组合根据倒推 ,从后面往前组合

用list2存放上一次组合数据，list存放本次组合数据


输入为23 2对应 “abc” 3对应“def”
第一次 list={d,e,f} list2 = null
第二次 list2 = {d,e,f} ，list为新组合的List<String>
a和list2组合放入list
b和list2组合放入list
c和list2组合放入list

list{
a{d,e,f},
b{d,e,f},
c{d,e,f}
}
新的list{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}



若输入为 234

第一次 list = {g,h,i} list2 = null
第二次 list2 = {g,h,i} list为新组合的List<String>
d和list2组合放入 list 
e和list2组合放入 list 
f和list2组合放入 list 
list = {
d{g,h,i},
e{g,h,i},
f{g,h,i}
}
list = {dg,dh,di,eg,eh,ei,fg,fh,fi}
第三次 list2 = {dg,dh,di,eg,eh,ei,fg,fh,fi} list为新组合的List<String>
a和list2组合放入 list 
b和list2组合放入 list 
c和list2组合放入 list 
list = {
a{dg,dh,di,eg,eh,ei,fg,fh,fi},
b{dg,dh,di,eg,eh,ei,fg,fh,fi},
c{dg,dh,di,eg,eh,ei,fg,fh,fi}
}




class Solution {
    public static List<String> letterCombinations(String digits) {
    	if(digits == null || digits.length() == 0) {
    		return new ArrayList<String>();
    	}
    	HashMap<Integer, String> hashMap = new HashMap<Integer, String>();
    	hashMap.put(2, "abc");
    	hashMap.put(3, "def");
    	hashMap.put(4, "ghi");
    	hashMap.put(5, "jkl");
    	hashMap.put(6, "mno");
    	hashMap.put(7, "pqrs");
    	hashMap.put(8, "tuv");
    	hashMap.put(9, "wxyz");
    	List<String> list = new ArrayList<String>();
    	int value = Integer.valueOf(digits);
    	for (int i = 0; i < digits.length(); i++) {
			//获取本次需要组合的字符串
			StringBuilder stringBuilder = new StringBuilder(hashMap.get(value%10));
			//初始化
			if(list.size() == 0) {
    			for(int k = 0 ; k < stringBuilder.length() ; k++) {
    				list.add(stringBuilder.substring(k, k+1));
    			}
    			value /= 10;
    			continue;
    		}
    		//list2存放上一次组合数据，list存放本次组合数据
    		List<String>  list2  = list;
			list = new ArrayList<String>();
    		for (int j = 0; j < stringBuilder.length(); j++) {
    			for (String string : list2) {
					list.add(stringBuilder.substring(j, j+1)+string);
				}
			}
    		value /= 10;
		}
    	return list;
    }
}