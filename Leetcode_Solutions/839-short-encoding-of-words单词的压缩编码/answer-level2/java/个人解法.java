### 解题思路
总体思路：
通过讲words按长度从小到大排序，然后看后面的string的尾部是否包含当前string，不包含就装入list，最后将计算list长度（要加#号的长度）。
分步：
1.利用Array进行排序。
2.从短到长遍历words。
3.对于每一个words[i]，首先设置flag为true，标记后面是否有尾部包含关系。
4.遍历后面i到words.length的单词，判断比自己长或者和自己相等长度的字符串的最后几位是不是和自己相同，相同的话将flag设为false；
5.不相同的话，就加入list中。
6。遍历list计算长度。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
List<String> list = new ArrayList<String>();
		int l = 0;
		int len = words.length;
		//排序
		arrangment(words);
		//从短到长遍历words
		for(int i = 0; i < len ; i++) {
			//System.out.println(" i = "+ i);
			int leni = words[i].length();
            boolean flag = true;
			//判断比自己长或者和自己相等长度的字符串的最后几位是不是和自己相同，相同的话将flag设为false；
			for (int j = i + 1 ;j <len ;j++) {
				int lenj = words[j].length();
				//System.out.println("sub = " +words[j].substring(lenj - leni, lenj ));
				if(words[i].equals(words[j].substring(words[j].length() - words[i].length(), words[j].length()))) {
					//System.out.println(words[i] + " break");
					flag = false;
				}
			}
			if(flag == true) {
				list.add(words[i]);
				//System.out.println("add "+ words[i]);
			}
		}
		//计算最终长度
		for(String s:list) {
			//System.out.print( s+ "#");
			l += s.length() + 1;
		}
		//System.out.println("l = " + l);
		return l;
		
    }
	//排序
	private static String[] arrangment(String[] words) {
		Arrays.sort(words,new Comparator<String>(){

			@Override
			public int compare(String s1, String s2) {
				//大于零返回s1，小于0返回s2
				return s1.length() - s2.length();
			}
			
		});
		return words;
	}
}
```