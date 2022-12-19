### 解题思路
此类题目都有一定的分析思路 代码也有一定的遍写技巧
如果Deque代替java原来的stack的话
Deque<String> path = new ArrayDeque<>();
push <=> addFirst
pop  <=> removeFirst
peek <=> peekFirst

### 代码

```java
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
import java.util.Deque;
import java.util.ArrayDeque;
class Solution {
    public List<List<String>> partition(String s) {
        //回溯算法 
        List<List<String>> list  = new ArrayList<>();

        if (s.length() == 0) {
            return list;
        }

        //使用栈保存路径 path
        //Stack<String> path = new Stack<>();
        //JDK推荐写法 ArrayDeque 线性数组实现的双端队列 LinkedList 链式列表实现的双端队列
        Deque<String> path = new ArrayDeque<>();
        
        //回溯算法
        dfs(s, 0, list, path);

        return list;
    }

    //回溯算法 s 原字符串 k 到了那一个值
    private void dfs(String s, int k, List<List<String>> list, Deque<String> path) {
        //递归入口
        if (k == s.length()) {
            list.add(new ArrayList(path));
            return;
        }

        for (int i = k; i < s.length(); i++) {
            //判断截取之前的字符串是否为回文串
            if (!isPalindrome(s, k, i)) {
                continue;
            }
            
            //path 增加路径 入栈
            path.addLast(s.substring(k, i + 1));

            //继续开始递归
            dfs(s, i+1, list, path);

            //回溯--撤销上一步操作
            path.removeLast();
        }
    }

    //判断字符串是否为回文字符串 判断回文 这段可以 写出dp表的形式
    private boolean isPalindrome(String s, int i, int j) {
        
        if (i - j > 0) {
            return false;
        }
        
        //循环判断回文字符串
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

}
```