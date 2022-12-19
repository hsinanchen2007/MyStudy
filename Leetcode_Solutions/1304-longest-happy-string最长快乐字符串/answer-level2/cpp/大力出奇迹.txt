大力出奇迹，第一次在周赛写100行才能AC的代码……纪念一下

思路：找到a,b,c中最大的数，每隔2个最大数插入一个其他数。如果其他数用完，那么就结束了。如果没用完，显然可以证明，假如最大是a, 那么还剩下的 b + c 一定可以插入 res 中，并且不出现连续3个。同样只要隔 2 个插 1 个就行了。

```c++
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int mx = a;
        if (a >= b && a >= c) mx = a;
        else if (b >= a && b >= c) mx = b;
        else mx = c;
        if (!a && !b && !c) return "";
        
        string res;
        int aa = a, bb = b, cc = c;
        int i;
        int runOut = 0;  // 非最大数是否用完
        for (i = 0; i <= mx - 2; i += 2) {
            if (mx == a) {
                res += "aa";
                if (bb > 0) {
                    res += 'b'; bb --;
                } else if (cc > 0) {
                    res += 'c'; cc --;
                } else {
                    runOut = 1;
                    break;
                }
            }
            else if (mx == b) {
                res += "bb";
                if (aa > 0) {
                    res += 'a'; aa --;
                } else if (cc >0) {
                    res += 'c'; cc --;
                } else {
                    runOut = 1;
                    break;
                }
            }
            else if (mx == c) {
                res += "cc";
                if (aa > 0) {
                    res += 'a'; aa --;
                } else if (bb > 0) {
                    res += 'b'; bb --;
                } else {
                    runOut = 1;
                    break;
                }
            }
        }
        
        // 最大数已不够2个，那么看其他数是否用完
        // 用完了就不能继续接最大数了，因为前面已经接了2个了，再接会形成3连
        if (i != mx && runOut == 0){
            if (mx == a) {
                res += "a";
                if (bb > 0) {
                    res += 'b'; bb --;
                } else if (cc > 0) {
                    res += 'c'; cc --;
                }
            }
            else if (mx == b) {
                res += "b";
                if (aa > 0) {
                    res += 'a'; aa --;
                } else if (cc >0) {
                    res += 'c'; cc --;
                }
            }
            else if (mx == c) {
                res += "c";
                if (aa > 0) {
                    res += 'a'; aa --;
                } else if (bb > 0) {
                    res += 'b'; bb --;
                }
            }
        }
        
        if (mx == a) aa = 0;
        else if (mx == b) bb = 0;
        else if (mx == c) cc = 0;
       
        // 插入剩余的数
        i = 0;
        while (aa) {
            res.insert(i, "a");
            aa --;
            i += 2;
        }
        
        i = 0;
        while (bb) {
            res.insert(i, "b");
            bb --;
            i += 2;
        }
        
        i = 0;
        while (cc) {
            res.insert(i, "c");
            cc --;
            i += 2;
        }
        return res;
    }
};
```