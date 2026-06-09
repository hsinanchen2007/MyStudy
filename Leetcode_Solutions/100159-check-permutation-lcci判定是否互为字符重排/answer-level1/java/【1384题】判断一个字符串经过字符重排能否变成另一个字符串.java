**方法一：使用字符串的repalce()方法**
```
class Solution {
    /**
    * 思路：
    * (1) 如果两个字符串能通过字符重排互相变化，说明两个字符串拥有的字符相同并且每个字符的个数相同。
    * (2) 遍历一个字符串字符，调用字符串方法replace()替换为空字符串""。
    * (3) 判断替换后的两字符串长度，如果不等则不能通过字符重排互相变化，否则直至遍历结束返回true。
    */
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()){
            return false;
        }
        for (int i = 0; i < s1.length(); i++){
            int len1 = s1.replace(String.valueOf(s1.charAt(i)), "").length();
            int len2 = s2.replace(String.valueOf(s1.charAt(i)), "").length();
            if(len1 != len2){
                return false;
            }
        }
        return true;
    }
}
```

**方法二：通过字符数组的排序**
```
class Solution {
    /**
    * 思路：
    * (1) 如果两个字符串能通过字符重排互相变化，则两个字符串可以通过字符重排变成相同的字符串。
    * (2) 将两个字符串分别转为字符数组并排序。
    * (3) 将排完序的两个字符数组转为字符串比较是否相同，如果相同返回true，否则返回false。
    */
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()){
            return false;
        }
		char[] c1=s1.toCharArray();
        Arrays.sort(c1);
        char[] c2=s2.toCharArray();
        Arrays.sort(c2);
        return new String(c1).equals(new String(c2));
    }
}
```

**方法三：使用ASCII码值记录字符**
```
class Solution {
    /**
    * 思路：
    * (1) 用一个长度256的int数组表示所有ACCII码字符，用来存储每个字符出现的次数。
    * (2) 遍历字符串s1，字符每出现一次，该字符对应的数组位置值加一。
    * (3) 遍历完s1之后遍历字符串s2，字符每出现一次，该字符对应的数组位置值减一。
    *       如果某个字符次数不够减，则返回false，否则直至遍历结束返回true。
    */
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()){
            return false;
        }
        int[] temp = new int[256];
        for (int i = 0; i < s1.length(); i++) {
            char c = s1.charAt(i);
            temp[c]++;
        }
        for (int i = 0; i < s2.length(); i++) {
            char c = s2.charAt(i);
            if (temp[c] == 0){
				return false;
			}else{
				temp[c]--;
			}
        }
        return true;
    }
}
```
