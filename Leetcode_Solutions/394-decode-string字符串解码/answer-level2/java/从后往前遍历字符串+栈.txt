![2020032801.PNG](https://pic.leetcode-cn.com/05414557e0afb498d50909ebfbeaeff3eba5e84beac52528b10a3f97d2c5a9a6-2020032801.PNG)
### 解题思路
 思路-----从后往前遍历整个字符串
 1. 声明辅助栈stack, 栈的类型为String, 记录遍历过程中的字母字符串或者"]"
 2. 声明StringBuilder s1记录遍历过程中遇到的字母, 如果遇到的是字母则将字母不断添加到s1中,
 3. 将s1逆序后的字符串压入栈中:
 --3.1 索引i==0时,且字符串s在(i+1)处为字母, 则直接将s1逆序过后的字符串压入栈中
 --3.2 当遇到'['时, 声明int index=i, 用while循环从index位置开始往前遍历找到需要重复的次数, 声明StringBuilder c 记录数字字符串
 --3.2 (在寻找重复次数的过程中, 当遇到字母、'['或者']'时, 表明已经找到需要重复的次数, 停止遍历, 记需要重复的次数为cnt
 4. 声明StringBuilder st 记录当前需要重复的字符串, 将stack栈顶的元素不等于"]"的时候, 将栈的元素不断弹出, 并添加到st中, 当遇到栈顶为"]"时, 停止元素出栈
 5. 将st对应的字符串重复cnt次, 将重复后的结果记录在StringBuilder sb中, 先将栈顶中的"]"元素弹出(此时消除一对括号"[]"), 再将sb字符串压入栈中
 6. 将步骤2-5中涉及的变量重新初始后, 再继续往前遍历, 重复步骤2-5
 7. 遍历完成后, 声明StringBuilder out记录结果, 将栈中的元素不断弹出, 并将弹出的元素添加到out中
 8. 最后返回out对应的字符串
### 代码

```java
class Solution {
    public String decodeString(String s) {
        Deque<String> stack = new LinkedList<>();
        StringBuilder out = new StringBuilder();
        StringBuilder s1 = new StringBuilder();
        for(int i=s.length()-1;i>=0;i--){
            if(s.charAt(i)==']'||Character.isLetter(s.charAt(i))){
            	if(Character.isLetter(s.charAt(i))) {
            		s1.append(s.charAt(i));
            	}else if(s.charAt(i)==']') {
                    //先将字母构成的字符串压入栈中
                    stack.push(s1.reverse().toString());
                    //再将"]"字符串压入栈中
                    s1 = new StringBuilder();
                    s1.append(s.charAt(i));
                    stack.push(s1.toString());
                    s1 = new StringBuilder();
            	}
            	if(i==0) {
            		stack.push(s1.reverse().toString());
            		 
                    s1 = new StringBuilder();
            	}
            }else if(s.charAt(i)=='['){
            	stack.push(s1.reverse().toString());
                int index = i-1;
                StringBuilder c = new StringBuilder();
                while(index>=0&&s.charAt(index)!=']'&&!Character.isLetter(s.charAt(index))&&s.charAt(index)!='['){
                    c.append(s.charAt(index));
                    index--;
                }
                int cnt =0;
                cnt = Integer.valueOf(c.reverse().toString());
                StringBuilder st = new StringBuilder();
                while(!stack.peek().equals("]")){
                    st = st.append(stack.pop());
                }
                stack.pop();
                StringBuilder sb = new StringBuilder();
                for(int j=0;j<cnt;j++){
                    sb.append(st.toString());
                }
                stack.push(sb.toString());
                s1 = new StringBuilder();
            }
        }
        while(!stack.isEmpty()){
            out.append(stack.pop());
        }
        return out.toString();
    }
}
```