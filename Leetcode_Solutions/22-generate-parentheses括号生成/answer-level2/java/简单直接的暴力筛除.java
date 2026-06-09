### 解题思路
我们可以简单的这样想，题目给我n对括号
总共代表有 2*n 位
每个位置只有左括号和右括号两种状态，
可以分别用0,1代表
所以，该问题可以转换为从0~pow(2,2*n)-1中
找到符合括号语法的，然后加入其中

至于判断括号是否合法这个问题，可以20.有效的括号了解一下

这里的时间复杂度显然达到了 2的2*n次方 乘上 4n

虽然low了点，自己还是想出来了

### 代码

```java
class Solution {

    public List<String> generateParenthesis(int n) {


        List<String> res = new ArrayList<String>(); 

        Map<Integer, Character> index = new HashMap<Integer, Character>();

        index.put(0, '('); // 0代表左括号
        index.put(1, ')'); // 1代表右括号

        int i, j;
        for (i = 0; i < Math.pow(2, 2 * n ); i++) {

            int m = i;

            StringBuilder cur = new StringBuilder();
            Stack judge = new Stack();
            //注意这里是从右往左读，故应该先遇到的是')' 
            //这里是在判断 括号是否有效
            for (j = 0; j < 2 * n; j++) {

                if (m % 2 == 1) judge.push(1);
                else if (m % 2 == 0 && !judge.isEmpty()) judge.pop(); 
                else if (m % 2 == 0 && judge.isEmpty()) break;  
                m /= 2;
            }
            
            if(j!=2*n||!judge.isEmpty()) continue;

  
            
            m = i;       
            for (j = 0; j < 2 * n; j++) {
                cur.append(index.get(m % 2));
                m /= 2;
            }
            //显然是从右往左去的，故应该颠倒过来
            res.add(cur.reverse().toString());

        }
        return res;

    }
}
```