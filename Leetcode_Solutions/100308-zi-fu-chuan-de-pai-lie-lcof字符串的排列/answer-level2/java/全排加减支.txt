### 解题思路
全排列问题，外加去重。
全排列思想：思想就是给字符串分为第一个字符和其他字符，然后不断递归，把其他字符中分成第一个字符和其他字符，最后不能在分的时候，停止。
代码思路：分为前缀和主题，最后在分到只有一个字符的时候，组合前缀和主体，写入ArrayList中即可。

去重思想：该过程只会在字符串中出现了重复字符时候出现，当固定的字符重复时候，就会出现重复，停止即可。
代码思路：每一层第一次固定一定不会出现重复，记录到list中，当交换位置时候，判断固定位置是否已经存在，存在就停止这一个分支后续的递归。
![IMG_2012.jpg](https://pic.leetcode-cn.com/38681e4ef57b6521f9839e9c4e865762be7b90b709f19a7f4b0df8f333423660-IMG_2012.jpg)


### 代码

```java
class Solution {
    static ArrayList<String> ls=new ArrayList();
    public String[] permutation(String s) {
        ls.clear();
arrange("", s);
		String str[] = ls.toArray(new String[]{});
        return str;
    }
private static void arrange(String prefix,String subject) {
		if(subject.length()==1) {
			String he=prefix+subject;
//			if(!ls.contains(he))
			ls.add(he);
			return;
			}
		//位置的第一个数，不用减支
		arrange(prefix+subject.substring(0, 1)
		, subject.substring(1));
		ArrayList<String> l=new ArrayList();
		l.add(subject.substring(0, 1));
		for (int i = 1; i < subject.length(); i++) //i=1表示从第二位开始换
		{	
			String str1=swap(subject, i);
			//重复就减，不重复就停止
			if (l.contains(str1.substring(0, 1))){
				
			}
			else {
				l.add(str1.substring(0, 1));
			arrange(prefix+str1.substring(0, 1)
					, str1.substring(1));
				}
		}

	}
	private static String swap(String str,int i) {
		if (i==0) 
			return str;
		 String a=str.substring(i,i+1);
		 str=a+str.substring(1, i)+str.substring(0, 1)
				 +str.substring(i+1, str.length());
		return str;
		// TODO Auto-generated method stub

	}
	
	 
}

```