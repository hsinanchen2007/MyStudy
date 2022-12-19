1.双栈法
```
class Solution {
    public String decodeString(String s) {    
        Stack<Integer> timesStack = new Stack<>();
        Stack<String>  strStack = new Stack<>();
        StringBuilder res = new StringBuilder();
        int times = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == '[') {//遇到左括号要重新开始, 把之前的存入栈
                timesStack.push(times);
                times = 0;
                strStack.push(res.toString());
                res = new StringBuilder();
            } else if(c == ']') {//需要弹栈, 和左括号之前的连接
                String str = getTimesString(res.toString(), timesStack.pop());
                res = new StringBuilder(strStack.pop());
                res.append(str);
            } else {//遇到左和右括号之前
                if(c >= '0' && c <= '9') {
                    times = times * 10 + c - '0';
                } else {
                    res.append(c);
                }
            }
        }
        return res.toString();
    }
    
    public String getTimesString(String str, int times) {
        StringBuilder res = new StringBuilder();
        while(times-- > 0) {
            res.append(str);
        }
        return res.toString();
    }
}
```
2.递归法
```
class Solution {
    
    class Data {
        String str;
        int end;
        public Data(String s, int e) {
            str = s;
            end = e;
        }
    }
    
    public String decodeString(String s) {
        return process(s, 0).str;
    }
    
    
    public Data process(String s, int i) {
        StringBuilder res = new StringBuilder();
        int times = 0;
        while(i < s.length() && s.charAt(i) != ']') {
            char c = s.charAt(i);
            if(c == '[')  {//递归处理
                Data data = process(s, i + 1);
                res.append(getTimesString(data.str, times));
                times = 0;
                i = data.end + 1;
            } else {//说明是数字或者字符
                if(c >= '0' && c <= '9') {
                    times = times * 10 + c - '0';
                } else {
                    res.append(c);
                }
                i++;
            }
        }
        return new Data(res.toString(), i);
    }  
    
    public String getTimesString(String str, int times) {
        StringBuilder res = new StringBuilder();
        while(times-- > 0) {
            res.append(str);
        }
        return res.toString();
    }
    
    
}
```

