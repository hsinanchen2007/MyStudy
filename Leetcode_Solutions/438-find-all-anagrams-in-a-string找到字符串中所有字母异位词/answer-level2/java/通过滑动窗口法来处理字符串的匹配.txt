代码有点啰嗦，没有继续简化，但是逻辑比较清晰


```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {

        //使用移动窗口法，首先是建立成窗口，然后将窗口移动
        //关于目标字符的排列，只需要记录字符出现的次数就行了。而不用目标字符p的所有排列

        //创建一个数组列表，用于存放目标字符串中字符的个数
        int[] ch = new int[26];

        //创建一个list，用于存放结果
        List<Integer> res = new ArrayList<>();

		//防止空字符
        if (s == null || p == null || s.length() < p.length())
            return res;
       
	   //将字符串转为数组
        char[] sChars = s.toCharArray();
        char[] pChars = p.toCharArray();

        //定义左右指针与剩余待匹配的数量
        int l = 0;
        int r = 0;
        int rest = pChars.length;

        //遍历p，得到p中各个字符的个数
        for (char c : pChars)
        {
            ch[c-'a']++;
        }

        //生成窗口
        for (; r <pChars.length ; r++)
        {
            //拿到字符
            char temp = sChars[r];
            //然后与ch数组进行对比，如果该字符的数>0则说明是p中的字符
            //然后执行字符的操作
            ch[temp-'a']--;
            if (ch[temp-'a']>=0)
            {
                rest--;
            }
        }
        r--; //将右指针复位到窗口的最右端的数字
		
		//rest=0说明全部匹配完
        if (rest==0)
        {
            res.add(l);
        }

        //进行移动窗口操作
        //首先是l指针右移一位，注意将一个字符移除窗口之后，ch数组对应的操作
        while (r<sChars.length-1)   //循环移动窗口
        {
            //判断左指针右移一位的字符是不是在s中
            char temp = sChars[l++];
            if (ch[temp-'a']>=0)  //满足条件说明此字符在p中
            {
                //在p中的字符移出去之后，就要个操作
                rest++;
            }
            ch[temp-'a']++;  //该字符不在窗口中，就要将字符个数恢复到原来的值

            //判断右指针右移一位的字符是不是在s中
            char temp1 = sChars[++r];
            ch[temp1-'a']--;
            if (ch[temp1-'a']>=0)
            {
                rest--;
            }
            if (rest==0)
            {
                //rest=0说明全部匹配完
                res.add(l);
            }
        }
        return res;
    }
}
```
