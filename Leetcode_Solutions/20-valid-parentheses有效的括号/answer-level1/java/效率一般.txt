### 解题思路
此处撰写解题思路

### 代码

```java
public class Subject005 {

    public static void main(String[] args) {
        Subject005 o = new Subject005();
        String test = "()";
        System.out.println("isValid：" + o.isValid(test));
        System.out.println("isValid1：" + o.isValid1(test));
    }


    /**
     *  思路1
     *  将 左右括号分别先放入俩个map，作为key，
     *  先对应的括号value之和为0
     *  循环字符串，遇到左括号将key压入栈中
     *  遇到右括号将key取map（mapRight）中的value和栈顶的key（mapLeft）取value做和若不为0
     *  则表示不是对应括号，可以直接返回fasle（此处是跳出循环）
     *  在最后判断下栈是否大小为0.放置左括号多的场景
     */
    public boolean isValid(String s) {
        Map<Character,Integer> mapLeft = new HashMap();
        mapLeft.put('(',1);
        mapLeft.put('[',2);
        mapLeft.put('{',3);

        Map<Character,Integer> mapRight = new HashMap();
        mapRight.put(')',-1);
        mapRight.put(']',-2);
        mapRight.put('}',-3);

        Stack<Character> stack = new Stack<>();
        boolean flag = true;
        for(char c: s.toCharArray()){
            if(mapLeft.containsKey(c)){
                stack.push(c);
            } else if(mapRight.containsKey(c)) {
                // 若栈中没有，那说明没有匹配的，因此返回错误
                if(stack.size() <= 0){
                    flag = false;
                    break;
                }

                if(mapRight.get(c) + mapLeft.get(stack.pop()) == 0){
                    continue;
                } else {
                    flag = false;
                    break;
                }

            }
        }
        if(stack.size() > 0 ){
            return false;
        }
        return flag;
    }


    /**
     *  上一个思路的优化,
     *  仅使用一个mapLeft，key 为左括号，value为又括号
     *  同样采用栈压入和压出的方式，判断时直接判断是否是value相等即可
     */
    public boolean isValid1(String s) {
        Map<Character,Character> mapLeft = new HashMap();
        mapLeft.put('(',')');
        mapLeft.put('[',']');
        mapLeft.put('{','}');

        Stack<Character> stack = new Stack<>();
        boolean flag = true;
        for(char c: s.toCharArray()){
            if(mapLeft.containsKey(c)){
                stack.push(c);
            } else  {
                if(stack.size() <= 0){
                    flag = false;
                    break;
                }

                if(c== mapLeft.get(stack.pop())){
                    continue;
                } else {
                    flag = false;
                    break;
                }

            }
        }
        if(stack.size() > 0 ){
            return false;
        }
        return flag;
    }

    /**
     *
     * @param s
     * @return
     */
    public boolean isValid2(String s) {

        String v ="(){}[]";



        return false;
    }


}
```