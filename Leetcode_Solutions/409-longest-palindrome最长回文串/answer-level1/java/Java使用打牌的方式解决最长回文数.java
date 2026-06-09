解题思路：类似于打牌，将对子打出，留下单牌，将字符串中不成对出现的元素留下，成对的去掉，最终得到的是所有不成对元素。
如果没有不成对的元素则回文数等于字符长度，否则等于字符长度-不成对元素总数+1。
（循环中不能使用remove直接删除，这里使用了迭代器进行元素的删除）
代码：
``` 
 public int longestPalindrome(String s) {
        List<Character> list=new ArrayList<>();
        Iterator<Character> iter = list.iterator();
        char[] ss=s.toCharArray();
        int i=0;
        for(char c1:ss){
            if(!list.contains(c1))list.add(c1);
            else{ 
                iter = list.iterator();
                while(iter.hasNext()){
                    char c2=iter.next();
                    if(c1==c2)iter.remove();
                }
                }
        }
        if(list.isEmpty())return s.length();
        return s.length()-list.size()+1;
    }
``` 