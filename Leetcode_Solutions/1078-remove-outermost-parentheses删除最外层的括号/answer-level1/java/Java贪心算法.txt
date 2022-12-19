```
public String removeOuterParentheses(String S) {
        StringBuilder result = new StringBuilder();//结果
        StringBuilder sb = new StringBuilder();//原语
        int num = 0;//记录左右括号的个数是否相等
        for (char c : S.toCharArray()) {//遍历字符串中的全部字符
            if (c == '(') {//如果是左括号，num加1
                num++;
            } else {//如果是右括号，num减1
                num--;
            }
            sb.append(c);//将字符添加到sb后面
            if (num == 0) {//如果num的值为0，说明此时的sb是原语
                result.append(sb.substring(1, sb.length() - 1));//把sb左右两端的括号去掉，添加到result末尾
                sb = new StringBuilder();//初始化sb
            }
        }
        return result.toString();
    }
```
