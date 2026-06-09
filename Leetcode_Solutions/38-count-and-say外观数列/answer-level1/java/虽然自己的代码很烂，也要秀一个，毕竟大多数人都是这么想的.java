```
package com.leetcode.easy;

import java.util.ArrayList;

public class SolutionCountAndSay_38 {
	/*
	 * 1 被读作  "one 1"  ("一个一") , 即 11。
     * 11 被读作 "two 1s" ("两个一"）, 即 21。
     * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
     * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
	 */

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(countAndSay(1));
		System.out.println(countAndSay(2));
		System.out.println(countAndSay(3));
		System.out.println(countAndSay(4));
		System.out.println(countAndSay(5));
		System.out.println(countAndSay(6));
		System.out.println(countAndSay(7));
		System.out.println(countAndSay(8));
		System.out.println(countAndSay(9));
		System.out.println(countAndSay(10));
		System.out.println(countAndSay(11));
		System.out.println(countAndSay(12));

	}
	
    @SuppressWarnings("unchecked")
	public static String countAndSay(int n) {
    	
    	//循环n次
    	String str ="1";
    	for(int i=1;i<n;i++){
    			//记录每次改变的字符串
    			StringBuffer sb=new StringBuffer();
    			sb.setLength(0);
    			//list 存切割的相同的字符串
    			ArrayList<String> list =new ArrayList<String>();
    			list =divideSameStr(str);
    			for(int m=0;m<list.size();m++){
    				String temp= list.get(m);
    				int tempNum=temp.length();
    				sb.append(""+tempNum+temp.charAt(0));
    			}
    			str=sb.toString();	
    	}
    	return str;
        
    }
    
    @SuppressWarnings("rawtypes")
	public static ArrayList divideSameStr(String str) {
    	ArrayList<String> list =new ArrayList<String>();
    	//双重循环
    	for(int i=0;i<str.length();){
    		int index=0;
    		for(int j=i;j<str.length();j++){//j从i的位置开始
    			if(str.charAt(i)==str.charAt(j)){
    				index++;
    			}else
    				break;//不相等的退出截串
    		}
    		list.add(str.substring(i,i+index));
    		i=index+i;
    	}
    	return list;
    }
}

```
