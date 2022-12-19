### 解题思路
1、题目的意思
![QQ截图20200401100043.png](https://pic.leetcode-cn.com/30f1b9c39a32312d127edcbb4da48914da55e68f2773827d85905fd271fea4c8-QQ%E6%88%AA%E5%9B%BE20200401100043.png)

2、（你需要从中选出 任意 一组有效括号字符串 A 和 B，使 max(depth(A), depth(B)) 的可能取值最小）任意一组A和B中，尽量让depth(A)=depth(B)才能使得值最小，seq对应的栈中，每个左括号对应一个深度，而这个左括号不是A的就是B的，如果想让A和B的深度接近的话，就将左括号按照奇数偶数分配给A和B，比如深度为1、2、3分别为ABA，则A和B的最大深度最接近。
3、题目的前提为字符串内的括号为有效括号，即完全的左右括号配对出现
4、题解的话，用一个整数值来记录当前深度，如果为嵌套左括号则深度加一，如果为左右相抵则不加1，如果为嵌套右括号则深度减一。将整数值为奇数的分配给A或B，为偶数的对应分配给B或A即可。


### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        char[] chars=seq.toCharArray();
        int[] res=new int [chars.length];
        int b=0;
        for (int i = 0; i < chars.length; i++) {
            if(chars[i]=='('){
                b++;
            }
            if(b%2==0){
                res [i]=1;
            }else {
                res [i] =0;
            }
            if(chars [i] ==')') b--;
        }
        return res;

    }
}
```