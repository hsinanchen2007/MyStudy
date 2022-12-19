### 解题思路
双指针，i指向开头，j指向末尾，分别向中间遍历，遇到元音时交换
具体看注释

### 代码

```java
class Solution {
     private final static HashSet<Character> vowels=new HashSet<>(
            Arrays.asList('a','e','i','o','u','A','E','I','O','U'));
    public String reverseVowels(String s) {
      int i=0;
      int j=s.length()-1;
      char[] result=new char[s.length()];//新建一个result数组来装交换后的字符串
      while(i<=j){//以leetcode为例，当i3,j=4时，ci=t,cj=c,执行完ci的赋值后，i++就结束了本次的循环，所以还有一次i=4,j=4的循环
        char ci=s.charAt(i);
        char cj=s.charAt(j);//contains接受object作为参数       
        if(!vowels.contains(ci)){//本来是含有相同的元素，返回true，但是加了！，就是不含有相同元素，返回true
            result[i]=ci;//ci的值赋给result相应的位置
            i++;
        }else if(!vowels.contains(cj)){
            result[j]=cj;//cj的值赋给result相应的位置
            j--;
        }else{
            result[i]=cj;
            i++;
            result[j]=ci;//交换元音的位置
            j--;
        }
      }   
        return new String(result);//转换为String类型输出
    }
}
```