![2020032401.PNG](https://pic.leetcode-cn.com/9b2f7d8c98902686b22764edee42001d47e72c88f9b191f6cd307e641bdcde79-2020032401.PNG)

### 解题思路
思路: 对字符串数组strs中的每个字符串进行排序, 再比较排序后的两个字符串是否相等, 进而找出字母异位词

### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> out = new ArrayList<>();
        String[] st = Arrays.copyOf(strs, strs.length);
        Map<String,String> map = SortString.sortString(st);
        for(String str:map.keySet()) {
        	String s = map.get(str);
        	String[] aStr = s.split(" ");
        	List<String> reStr = new ArrayList<>(); 
        	for(int i =0;i<aStr.length;i++) {
        		if(!aStr[i].equals("")) {
        			int in = Integer.valueOf(aStr[i]);
        			reStr.add(strs[in]);
        		}
        	}
        	out.add(reStr);
        	
        }
        return out;   
    }
}
//这里的哈希表是返回字符串数组strs中相同字符在strs中的索引值字符串, 其中索引值之间以空格间隔
class SortString{
    public static Map<String,String> sortString(String[] st){
        for(int i=0;i<st.length;i++){
            int len = st[i].length();
            int[] num = new int[len];
            for(int j=0;j<len;j++){
                num[j] = st[i].charAt(j)-'a';
            }
            Arrays.sort(num);
            StringBuilder sb = new StringBuilder();
            for(int k=0;k<num.length;k++){
            	
                sb.append((char)(num[k]+97));
            }
            st[i] = sb.toString();
        }
        Map<String,String> map = new HashMap<>();
        for(int i=0;i<st.length;i++){
        	String str = " "+i;
            if(!map.containsKey(st[i])) {
            	map.put(st[i], str);
            }else {
            	map.put(st[i], str+map.get(st[i]));
            }
        }
        return map;
    }
}
```