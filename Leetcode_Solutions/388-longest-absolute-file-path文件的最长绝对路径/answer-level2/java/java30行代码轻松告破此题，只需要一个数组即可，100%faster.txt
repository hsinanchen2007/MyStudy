1.分析分析分析，首先题中给的字符串是什么样的，是层层递进的。这意味着什么，如果我们一直往下走就能够走到文件的最底层，也就是说我们能够拿到带.的文件的路径长度，没有点就是0
2.第二个问题，如果我从最后一层出来了怎么办。如果我回到第五层，那么第五层前面的是不是仍旧有效，第五层后面的怎么办，重新填，没错，就是重新填值。
3，废话不多说，直接上代码，如果有不懂的地方欢迎在下面留言，通常这个力扣的通知可能会有问题，看到一定会及时回复，欢迎交流
```java
    public int lengthLongestPath(String input) {
        int max = 0, res = 0, k = 0, mark = 0;
        int[] v = new int[25];
        v[0] = -1;
        for(char ch : input.toCharArray()){
            if(ch == '\n'){
                v[k+1] = res + 1 + v[k];
                if(mark > 0)
                    max = Math.max(max, v[k+1]);
                res = 0; k = 0; mark = 0;
            }
            else if(ch == '\t')
                k++;
            else {
                if(ch == '.') mark = 1;
                res++;
            }
        }
        if(mark > 0) max = Math.max(max, res+1+v[k]);
        return max;
    }
```