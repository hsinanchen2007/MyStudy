    public String convert(String s, int numRows) {
        //单行或者字符串长度那么多行就直接返回原字符串
        if (numRows == 1 || numRows >= s.length()) return s;
        //向下的标志刚开始为否
        boolean down = false;
        //存储每行的字符
        List<StringBuilder> list = new ArrayList();
        //避免空指针，先把每行都new一个StringBuilder
        for (int i = 0; i < numRows; i++) {
            list.add(new StringBuilder());
        }
        int n = s.length();
        //行号
        int index = 0;
        for (char c: s.toCharArray()) {
            list.get(index).append(c);
            //到0行和numRows - 1的时候标志反转
            if (index == 0 || index == numRows - 1) {
                down = !down;
            }
            //向下则+1 向上则-1
            index += down ? 1 : -1;
        }
        StringBuilder res = new StringBuilder();
        for (StringBuilder str: list) {
            res.append(str);
        }
        return res.toString();
    }