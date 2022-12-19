# 贪心思想

这题的思路首先在于如何处理这个消除字母的标准，也就是贪心怎么贪。设想一下，如果是我们自己来处理这个问题（人脑思索），你会怎么思考。我是想到先看一下当前字母前面有没有字典序比它大的字母（也就是ascii码比它大的），如果有的话，看看这个字母在后面的串中是不是还会出现，如果不出现，就不要动它了，如果出现了，就把他删掉。没错，就是这么简单的思维，（小声逼逼：其实我感觉很多题人脑自己都有解法，但是我们只看到了结果没有搞清楚自己大脑这么运作的步骤和原理，我每次想问题习惯先想想我的大脑怎么思考的，就比如我一眼看出来bcabc,按照题目要求的序列是abc，那我是怎么看出来的。我觉得贪婪这个本性。。。。。。是吧，你懂得，反正就用计算机模拟自己贪婪地本性就好了哈哈）贪心部分解决以后就是怎么实现的问题了，这里我看了一下标签，有一个栈，然后我就想到了维护一个栈来记录这个答案的序列，通过出栈入栈来对字母序列实现动态的删除和更改（就之前刷leetcode也遇到过好多类似的，比如雨水那题）。最后就是编码实现了。这里要敲黑板！！！划重点！！！在谈心判断的时候，不能单单只与当前的栈顶元素判断，应该不停地往栈里面判断。就是我代码的while循环那部分，要仔细看一下。因为bcabc这个样例，如果b入栈c入栈a在判断的时候只把c拿出来的话结果就是babc，这是个小坑。我都有写注释的，可能我说的不是太清楚，你们可以评论问我的。
```
    public String removeDuplicateLetters(String s) {
        if (s.length()==0)
            return  new String();
        int[] words = new int[26];//记录字母出现的次数，用来判断该串后面是否还有这个字母
        boolean[] isIn = new boolean[26];//用来判断这个字母是否已经进栈
        for (int i=0;i<s.length();i++){//统计字母个数
            words[s.charAt(i)-'a']++;
        }
        Stack<Character> stack = new Stack<>();
        for (int i=0;i<s.length();i++){
            words[s.charAt(i)-'a']--;
            if (!isIn[s.charAt(i)-'a']) {//先判断栈中没有这个字母，如果有这个字母无需进行任何操作直接跳过即可
                while(!stack.isEmpty()) {
                    if (!stack.isEmpty() && (s.charAt(i) - 'a' < stack.peek() - 'a' && words[stack.peek() - 'a'] > 0)) {//如果当前字母的字典序小于栈顶字母且栈顶字母在该串的后面仍存在
                        isIn[stack.peek() - 'a'] = false;//将栈顶字母设置为不存在栈中
                        stack.pop();//使其出栈
                    }
                    else{
                        break;//处理完后直接跳出
                    }
                }
                    stack.push(s.charAt(i));//如果栈中没有这个字母，且这个字母的字典序正好大于栈顶字母就直接入栈
                isIn[s.charAt(i)-'a'] = true;//标记栈中已经有该字母
            }
        }
        StringBuilder result = new StringBuilder();
        while(!stack.isEmpty()){
            result.append(stack.pop());//将栈中字母添加
        }
        result.reverse();//倒转字符串
        String last = result.toString();
        return last;
    }
```

