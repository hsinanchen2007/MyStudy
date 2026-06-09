此题可以借助“栈的题型：对称的括号”来解决
    遇到'('就新建一个TreeMap集合入栈，遇到')'就将Map集合出战，计算()其中的原子数量并将结果遍历添加到栈顶的Map集合中。分别研究字符串中字符为'('、')'、大写字母开头的元素名称 这三种情况。
    具体流程见代码中的注释，特别说明选用TreeMap的原因是为了保证元素的顺序性。
```
/**
     * 方法：栈，直接使用count栈来模拟调用堆栈代替递归
     * 时间复杂度：O(n^2)，空间复杂度：O(n)。
     * @param formula 输入一个化学式
     * @return 返回化学式中的各个原子数量
     */
    public String countOfAtoms(String formula) {
        //获取字符的长度
        int N = formula.length();
        //stack栈中使用Map集合用于存储原子名称和它对应的数量
        Stack<Map<String,Integer>> stack = new Stack<>();
        //往栈中添加一个TreeMap，使用TreeMap保证插入元素的顺序性。
        stack.push(new TreeMap<>());
        //遍历字符串中的字符
        for(int i = 0; i < N;){
            //如果formula字符串中遇到(就新建一个TreeMap用于计算()中的原子数量
            if(formula.charAt(i) == '('){
                stack.push(new TreeMap<>());
                i++;
            }
            //遇到‘)’时结束这个()中TreeMap中的原子数量的计算
            else if(formula.charAt(i) == ')'){
                //将栈顶的Map集合取出，即为()中的原子集
                Map<String,Integer> top = stack.pop();
                //iStart为()外的第一个数字或者原子， 作用是为了计算()中的原子的数量积。
                int iStart = ++i, multiplicity = 1;
                //遇到数字将i自增，计算原子数量
                while(i < N && Character.isDigit(formula.charAt(i))) i++;
                if(i > iStart) multiplicity = Integer.parseInt(formula.substring(iStart,i));
                for(String c : top.keySet()){
                    int v = top.get(c);
                    //往栈顶的TreeMap中添加()中的原子和对应的原子数量。peek()为看一眼栈顶元素。
                    //此处栈顶的TreeMap即父()中的TreeMap原子:数量集合。
                    stack.peek().put(c,stack.peek().getOrDefault(c, 0) + v * multiplicity);
                }
            }
            else{//没有遇到‘(’和‘)’ 的情况下，就很简单。
                int iStart = i++;
                while(i < N && Character.isLowerCase(formula.charAt(i))) i++;
                String name = formula.substring(iStart,i);
                //表示两个或多这个字符组成的原子
                iStart = i;
                while(i < N && Character.isDigit(formula.charAt(i))) i++;
                int  multiplicity = i > iStart ? Integer.parseInt(formula.substring(iStart, i)) : 1;
                //往栈顶的TreeMap中添加()中的原子和对应的原子数量。peek()为看一眼栈顶元素。
                stack.peek().put(name,stack.peek().getOrDefault(name, 0) + multiplicity);
            }
        }
        StringBuilder ans = new StringBuilder();
        //遍历栈中的Map集合
        for(String name : stack.peek().keySet()){
            ans.append(name);
            int multiplicity = stack.peek().get(name);
            //只有当multiplicity大于1的时候才会添加原子的数量
            if(multiplicity > 1) ans.append("" + multiplicity);
        }
        return new String(ans);
    }
```
