class Solution {
        public static String reverseWords(String s) {
            String[] a=s.split(" ");//根据空格分成数组
            String r="";
            StringBuffer sb ;
            for(int i=0;i<a.length;i++){
            	sb=new StringBuffer(a[i]);//对分隔后的每个字符串进行反转，只有StringBuffer中才有这个函数
            	r=r+sb.reverse()+" ";//拼接字符使要加会空格
            }
            return r.trim();//由于拼接最后一个字符串时多加了一个空格，前后去空格
        }
}