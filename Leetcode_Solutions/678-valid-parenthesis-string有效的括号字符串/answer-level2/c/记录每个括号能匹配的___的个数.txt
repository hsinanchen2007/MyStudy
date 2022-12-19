如果没有"*"的干扰，那么只要遍历字符遇到"("入栈，遇到")"出栈即可。遇到以下两种情况判定为括号不匹配：
1、字符串遍历结束，栈非空。
2、遇到字符")"，栈已空。
但是由于"*"的出现，我们需要在上面两个条件里，额外的增加对"*"的判断，这时括号不匹配的条件变为：
1、字符串遍历结束，栈非空，并且栈里存在一个"("，没有可以跟它匹配的"*"。
2、遇到字符")"，栈已空，同时它之前没有一个"*"跟它匹配。
要实现这个目的，我们就需要记录每个括号能匹配的"*"的个数。对于"("，每个"("后面的*是不一样的，所以每个"("后面的"*"需要单独统计。对于")"，我们只需要统计当前有多少"*"就可以了。
匹配*的时候，"("从最后的"*"开始匹配，而")"从最前面的"*"开始匹配。

举个例子：比如字符串"*(*))(*(*"
（1）字符"*"，星号总数+1
![image.png](https://pic.leetcode-cn.com/61be1313567051cc11be0e9ce117bb866b6a06f4e48ea77818e757c4cbe4efc3-image.png)
（2）字符"("，入栈
![image.png](https://pic.leetcode-cn.com/feaa62f0dcc573ec29ea7578f0c90e7d75cbce7396598fb09c463b285e5a8f82-image.png)
（3）字符"*"，星号总数+1，栈里的计数+1
![image.png](https://pic.leetcode-cn.com/87ef5420a4f4b06043b485dae5006d2a114a1c853a31a4b34fa25439d635301b-image.png)
（4）字符")"，出栈
![image.png](https://pic.leetcode-cn.com/5f72b7ce885aac5a2df6f878a801f1cfe514c7546506089aea68a16b0c6fcd81-image.png)
（5）字符")"，此时栈已经空了，但是还有"*"，此时将"*"的计数-1
![image.png](https://pic.leetcode-cn.com/e063ffb1cac54920241e719b298eea026b27281c486af5ebef7eb02901b724c3-image.png)
（6）字符"("，入栈
![image.png](https://pic.leetcode-cn.com/2b1e4b92f4649842ecaaaf71f75384798e3e8f4b562db02cca9ac8ed37411d40-image.png)
（7）字符"*"，星号总数+1，栈里的计数+1
![image.png](https://pic.leetcode-cn.com/adf081ca1245408ecab8a4993c311f1dec8c34cbd9f484de3bfbbbd337aa2766-image.png)
（8）字符"("，入栈
![image.png](https://pic.leetcode-cn.com/5e37e24bb18672f19e9017dc01d4c468acf4c523bff6a1a46d9d06575d103d3d-image.png)
（9）字符"*"，星号总数+1，栈里的计数+1
![image.png](https://pic.leetcode-cn.com/fb2f85730ffaa1c048c2a4923f5f8cdadab930bced5f200f5578d876af31ec5a-image.png)
（10）最后遍历栈中的元素，看看每个元素后面是否有足够的"*"可以匹配。当前显示是匹配的。


参考代码如下：
```
#define MAX_LENGTH 100
bool checkValidString(char * s) {
    char stack[MAX_LENGTH+1] = {0};
    int top = 0;
    int starCount = 0;

    for(int i = 0; s[i] != 0; i++) {
        if (s[i] == '(') {
            top++;
        } else if (s[i] == ')') {
            if (top > 0) {
                top--;
                stack[top] = 0;
                continue;
            }

            if (starCount <= 0) {
                return false;
            }
            
            starCount--;
        } else if (s[i] == '*') {
            for (int j = 0; j < top; j++) {
                stack[j]++;
            }
            starCount++;
        }
    }

    if (top == 0) {
        return true;
    }

    for (int i = top-1; i >=0; i--) {
        if (stack[i] < top-i) {
            return false;
        }
    }
    return true;
}
```

