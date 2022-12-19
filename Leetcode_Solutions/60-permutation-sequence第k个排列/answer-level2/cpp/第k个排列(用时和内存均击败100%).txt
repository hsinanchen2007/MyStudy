### 解题思路
终极剪枝的dfs搜索树，框架和dfs类似，但是由于我们只需要得到第k个排列，所以我们只需要找到该路径即可，其余路径均为无效路径都剪枝掉。由于剪枝后路径唯一，所以相比一般的dfs or 回溯，我们不用做撤销选择，并且做选择时每层只会有一个节点符合要求，最后输出中间存储路径的变量即可， 比如例子中的(2->3->1>4)。
接下来就讲如何达到每次选择列表里有且只有一个节点满足要求，做法就是每个节点中额外存储两个变量start和sec，start的含义为包含该节点的路径最早出现在第（start+1）排列，显然根节点的start=0；sec表示其每个子节点包含的路径数区间， 它的值等于待排长度的阶乘（我们用toUse表示等待排序的元素），通过start和sec我们可以深度探索知道任何节点的start和sec，再通过与K值的大小比较，确定第k个排列在当前节点的的第几个子节点里面，从而确定唯一路径，当路径长度存到n-1时，说明已经排好，输出即可。

### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        string cur, s;
        int a[10] = {0};
        for (int i = 1; i <= n; i++) {
             s += (i+'0');
             a[i] = Fac(i);
        }
        getKth(s, a, n, k, 0, a[n-1], cur);
        return cur;
    }

    void getKth(const string& s, 
                const int (&a)[10], 
                const int& n, 
                const int& k,
                int start, int sec, string& cur) {
        string toUse = s;
        if (cur.length() > 0) {
            for (int i = 0; i < cur.length(); i++) {
            	int pos = toUse.find(cur[i]);
                if (pos != string::npos) toUse.erase(pos, 1);
            }
        }
        if (cur.length() >= n-1) {
            cur.push_back(toUse[0]);
            return;
        }
        int s_new, j;
        for (j = 0; j < toUse.length(); j++) {
            if (k <= (start+(j+1)*sec)) break;
        }
        cur.push_back(toUse[j]);
        getKth(s, a, n, k, start+j*sec, a[toUse.length()-2], cur);
    }

    int Fac(int n) {
        if (n == 1) return 1;
        else return n * Fac(n-1);
    }
};
```