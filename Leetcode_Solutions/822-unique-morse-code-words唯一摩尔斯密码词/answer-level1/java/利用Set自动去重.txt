暴力解法，两重循环：
1.翻译字符串
2.外层循环加入Set集合，集合自动去重；
```
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] s={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
		Set<String> set=new HashSet<>();
        int index;
		for(int i=0;i<words.length;i++)
		{
			String temp="";
			for(int j=0;j<words[i].length();j++)
			{ 
                index=(int)words[i].charAt(j)-65-32;
				temp=temp.concat(s[index]);
			}
			
			set.add(temp);
		}
		return set.size();
    }
}
```

