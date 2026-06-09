1、将输入字符串拆分成单个字符并用栈input保存；
2、处理input栈，直至栈空；
3、建一个栈result来保存最终结果；
4、每次从input栈中pop元素，连续k次元素一样，说明需要删除，不需要push到栈result中；否则push到结果栈result中；
5、（重点）连续k次元素一样时，需要将k-1个元素从栈result中pop到栈input中，因为这k-1个元素可能和接下来的字符一样，并被删除。
```
class Solution {
    public String removeDuplicates(String s, int k) {
        if (k > s.length()) {
            return s;
        }

        char[] chars = s.toCharArray();
        Stack<Character> input = new Stack<>();
        for (int i = 0; i < chars.length; i++) {
            input.push(chars[i]);
        }
        Stack<Character> result = new Stack<>();
        char temp = input.pop();
        int sameNum = 1;
        while (!input.isEmpty()) {
            if (input.peek() == temp) {
                input.pop();
                sameNum++;
            } else {
                for (int i = 0; i < sameNum; i++) {
                    result.push(temp);
                }
                temp = input.pop();
                sameNum = 1;
            }
            if (sameNum == k) {
                for (int i = 0; !result.isEmpty() && i < k-1; i++) {
                    input.push(result.pop());
                }
                temp = input.pop();
                sameNum = 1;
            }
        }
        for (int i = 0; i < sameNum; i++) {
            result.push(temp);
        }
        StringBuilder stringBuilder = new StringBuilder();
        while (!result.isEmpty()) {
            stringBuilder.append(result.pop());
        }
        return stringBuilder.toString();
    }
}
```
