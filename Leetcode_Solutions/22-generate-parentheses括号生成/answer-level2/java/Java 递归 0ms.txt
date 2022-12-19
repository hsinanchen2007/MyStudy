```
    List<String> rtnList = new ArrayList<String>();
    char[] s;
    public List<String> generateParenthesis(int n) {
        s = new char[2 * n];
        generate(n, n, 0);
        return rtnList;
    }

    /**
     * 递归生成括号列表
     * @param left 左括号剩余可用数量
     * @param right 右括号剩余可用数量
     * @param index 当前要处理的字符位置索引
     */
    private void generate(int left, int right, int index){
        if(left > 0) {
            s[index] = '(';
            generate(left - 1, right, index + 1);
        }
        //如果右括号剩余数量大于左括号，表明已使用左括号数多于已使用右括号数，此时可以添加一个右括号
        if(right > left) {
            s[index]=')';
            generate(left, right - 1, index + 1);
        }
        if(right == 0){
            rtnList.add(String.valueOf(s));
            return;
        }
    }
```
