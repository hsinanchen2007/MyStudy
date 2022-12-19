### 解题思路
用一个队列实现全排列：
从前往后，每次取字符串的一个字符，
如果是数字：遍历队列，并将该数字字符添加到队列元素末尾；
如果是字母：遍历队列，并将该字母字符变化大小写后添加到队列元素末尾。

以下是 a1b2 示例：

![image.png](https://pic.leetcode-cn.com/a5bca00957d01de738c2153742cd87d22a097afb6f3433d7737c19a0c3f2c164-image.png)



### 代码

```java
class Solution {
    public List<String> letterCasePermutation(String S) {
        LinkedList<String> queue = new LinkedList();
        int length = S.length();
        if(length == 0) queue.add("");
        //特殊情况
        for(int i=0; i<=length-1; i++) {
            char temp = S.charAt(i);
            //是字母
            if(Character.isLetter(temp)) {
                if(queue.size() != 0) {
                    int queueSize = queue.size();
                    while(queueSize > 0) {
                        //队列中有元素
                        String beforeAdd = queue.poll();
                        StringBuilder builder = new StringBuilder(beforeAdd);
                        //添加小写末尾
                        builder.append(Character.toLowerCase(temp));
                        //添加到队尾
                        queue.add(builder.toString());
                        builder = new StringBuilder(beforeAdd);
                        //添加大写末尾
                        builder.append(Character.toUpperCase(temp));
                        //添加到队尾
                        queue.add(builder.toString());
                        queueSize--;
                    }
                } else {
                    //队列中没有元素
                    queue.add(Character.toLowerCase(temp)+"");
                    queue.add(Character.toUpperCase(temp)+"");
                }
            } else {
                //不是字母
                int queueSize = queue.size();
                //队列不为空
                if(queueSize != 0) {
                    while(queueSize > 0) {
                        StringBuilder builder = new StringBuilder(queue.poll());
                        builder.append(temp);
                        queue.add(builder.toString());
                        queueSize--;
                    }
                //队列为空
                } else {
                    queue.add(temp+"");
                }
            }
        }
        return queue;

    }
}
```