看到这道题，第一反应是递归，在创建构造器的时候直接将nestedList里的数据全部存储到list中，然后每次调用next()和hasNext()方法时从list中去获取和检查数据。先上代码吧，注释都在里面了。
```
public class NestedIterator implements Iterator<Integer> {

    private List<Integer> list;
    private int index;

    public NestedIterator(List<NestedInteger> nestedList) {
        list = new ArrayList<>();
        index = 0;
        splitList(nestedList);
    }
    //递归
    private void splitList(List<NestedInteger> nestedList){
        for(NestedInteger node: nestedList){
            //若当前节点是list，则递归
            if(!node.isInteger()){
                splitList(node.getList());
            }else{
                list.add(node.getInteger());
            }
        }
    }

    @Override
    public Integer next() {
        return list.get(index++);
    }

    @Override
    public boolean hasNext() {
        return index < list.size();
    }
}
```

但是由于是搜栈的标签找到这道题的，所以又想了想怎么用栈来解。大致想到利用先进后出的原则将nestedList中的元素逆向入栈，后来又参阅了其他大神的代码，最后整理如下：
```
public class NestedIterator implements Iterator<Integer> {

    private Stack<NestedInteger> stack;

    public NestedIterator(List<NestedInteger> nestedList) {
        this.stack = new Stack<NestedInteger>();
        int len = nestedList.size();
        //将nestedList中的元素逆向入栈
        for(int i = len - 1; i >= 0; i--){
            this.stack.push(nestedList.get(i));
        }
    }

    @Override
    public Integer next() {
        //栈顶元素经过hasNext()方法，已经确保为非List的NestedInteger，因此直接返回其值即可
        return stack.pop().getInteger();
    }

    @Override
    public boolean hasNext() {
        while(!stack.isEmpty()){
            //判断栈顶的元素是不是数值，若是则返回
            NestedInteger pop = stack.peek();
            if(pop.isInteger())
                return true;
            stack.pop();
            //否则拆解当前list，将其中元素逆向入栈，利用while循环保证栈顶元素是数值
            List<NestedInteger> nestList = pop.getList();
            for(int i = nestList.size() - 1; i >= 0; i--){
                this.stack.push(nestList.get(i));
            }
        }
        return false;
    }
}
```

若有什么不对的地方欢迎大家指出。