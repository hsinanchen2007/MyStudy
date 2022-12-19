
首做先，假设我们数是正常得满二叉树编码方式，根节点index是1，那假设父节点index是n，那左子树节点是2 * n， 右子树 2 * n + 1
在这个数组上找根节点的路径非常简单。

写一个转换函数，可以把正常上述的idnex 转换成题目中的index， 反之也可以将题目中的index转换成正常得index。

算法流程
1 首先将label转换成正常索引下的label
2 寻找在正常索引下的label到根的路径
3 反转路径
4 对路径中的每个索引转换成题目中的索引方法。
```
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        cout << label;
        label = getBefore(label);
        // 寻找根节点路径
        while(label >= 1){
            res.push_back(label);
            label /= 2;
        }
        reverse(res.begin(), res.end());
        for(int i = 0; i < res.size(); i ++){
            res[i] = getBefore(res[i]);
        }
        return res;
        
    }
    int getBefore(int label){
        int cnt = 1;
        while(pow(2, cnt - 1) <= label)
            cnt++;
        cnt --;
        if(cnt % 2 == 1)
            return label;
        else{
            int start = pow(2, cnt - 1);
            return pow(2, cnt) - 1 - label + start;
        }
    }
};
```