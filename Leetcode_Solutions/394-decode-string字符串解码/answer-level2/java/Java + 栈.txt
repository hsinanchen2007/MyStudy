执行用时 :2 ms, 在所有 java 提交中击败了55.92%的用户
内存消耗 :34.3 MB, 在所有 java 提交中击败了91.13%的用户

```
class Solution {
    public String decodeString(String s){
        StringBuffer sb = new StringBuffer();

        Stack<Character> stack = new Stack<Character>();

        StringBuffer encodedStr, k;

        for (char c : s.toCharArray()) {
            // 不是 ] 全部入栈
            if (c != ']') {
                stack.push(c);
            } else {
                boolean flag = false; // 遇到了数字

                k = new StringBuffer();
                encodedStr = new StringBuffer();

                while (! stack.isEmpty()){
                    if (stack.peek() >= '0' && stack.peek() <= '9') {
                        flag = true;

                        k.insert(0, stack.pop());
                    } else {

                        if (flag) {
                            // 遇到数字后又遇到字母，表示一个 k[encoded_string] 结束
                            break;
                        }

                        if (stack.peek() == '[') {
                            stack.pop();
                        } else {
                            encodedStr.insert(0, stack.pop());
                        }
                    }

                }

//                int kNum = Integer.valueOf(k.toString());
                int kNum = Integer.parseInt(k.toString());

                if (! stack.isEmpty()) {
                    // 如果还没结束，说明是个嵌套
                    // 需把刚刚处理的字符串重新入栈
                    for (int i = 0; i < kNum; i++) {
                        for (char ch : encodedStr.toString().toCharArray()) {
                            stack.push(ch);
                        }
                    }

                } else {

                    for (int i = 0; i < kNum; i++) {
                        sb.append(encodedStr);
                    }
                }

            }
        }

        int length = sb.length();
        while (! stack.isEmpty()) {
            // 如果还没结束，代表有普通字符串，直接加在后面
            sb.insert(length, stack.pop());

        }

        return sb.toString();
    }
}
```
