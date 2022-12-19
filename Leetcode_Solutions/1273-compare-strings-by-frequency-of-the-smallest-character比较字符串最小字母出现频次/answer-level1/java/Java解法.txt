思路：分别对words和queries计算其最小字符出现的次数，保存在forQueries和forWords数组中，然后两个for循环将forQueries中的与forWords中的一一比较即可。
package 字符串;

import java.util.Arrays;

public class leetcode1170 {
	public static void main(String[] args) {
		String queries[] =new String[] {"bbb","cc"};
		String words[] = new String[] {"a","aa","aaa","aaaa"};
		int a[]=numSmallerByFrequency(queries,words);
		1. for(int b:a) {
			System.out.print(b+" ");
		}
	}
	public static int[] numSmallerByFrequency(String[] queries, String[] words) {
		int res[]=new int[queries.length];//保存结果
		int forQueries[]=new int[queries.length];
		int forWords[]=new int[words.length];
		for(int i=0;i<queries.length;i++) {
			forQueries[i]=getMinLetter(queries[i]);
		}
        for(int i=0;i<words.length;i++) {
			forWords[i]=getMinLetter(words[i]);
		}
		
        for(int i=0;i<queries.length;i++) {
        	for(int j=0;j<words.length;j++) {
        		if(forQueries[i]<forWords[j]) {
        			res[i]++;
        		}
        	}
        }
		
		return res;

	}
	public static int getMinLetter(String s) {
		int result=1;
		char save[] =s.toCharArray();
		Arrays.sort(save);//这个排序函数十分重要
		for(int i=1;i<save.length;i++) {
			if(save[i]==save[i-1]) {
				result++;
			}else
				break;
		}
		return result;
	}
}
