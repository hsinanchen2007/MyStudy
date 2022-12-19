### 解题思路
第一次执行用时为**0ms**,但是我的内存开销太大了，总之记录一下吧。
* 这道“有效的括号”，经典的括号匹配问题，经典的解法就是用栈。*(是左括号就压栈，遇到右括号就弹栈，最后栈空了就说明匹配了，否则就是不匹配。)*
* 我的思路其实也是上面这样，不过我没有用栈，用两个数组模拟了栈的操作。*(是左括号一次填入数组，只要有右括号就和数组最后一个元素比较，只要不匹配就return false。最后如果遍历完了，整个左括号数组的元素都比较过了，就return true。)*
* 这里面定义了一个count，其作用很类似指针，一直指向所谓的“栈顶元素”，利用count的移动模拟压栈和弹栈。
### 代码

```java
class Solution {
    public boolean isValid(String s) {
        //s的长度是奇数直接返回false
        if(s.length()%2!=0){
            return false;
        }
        //如果是空串，直接返回true
        if(s.equals("")){
            return true;
        }
        char[] str = s.toCharArray();
        //ss数组用来保存左括号
        char[] ss = new char[s.length()];
        //count类似栈顶指针
        int count =0;
        for(int i=0;i<str.length;i++){
            //这里类似压栈
            if(str[i]=='('||str[i]=='['||str[i]=='{'){
                ss[count++] = str[i];
            }else{
                //这里的判断是为了防止第一个字符是有括号的情形，eg：")("
                if(count==0){
                    return false;
                }
                //类似于弹栈比较，只要有匹配不上的就返回false
                if(!isMatch(ss[--count],str[i])){
                    return false;
                }
            }
        }
        //这里count==0类似于栈空了，所有左括号都匹配上了
        if(count==0) {
	    	return true;	
	    }
	    return false;
    }
    //isMatch()函数用来判断左右括号是否匹配
    public boolean isMatch(char s1,char s2){
        if((s1=='('&&s2==')')||(s1=='['&&s2==']')||(s1=='{'&&s2=='}')){
            return true;
        }
        return false;
    }
}
```
![image.png](https://pic.leetcode-cn.com/87ff3407c71f0d74f41d78668f3b06338922a6dc537687323c2799a8c9ce0ed0-image.png)
