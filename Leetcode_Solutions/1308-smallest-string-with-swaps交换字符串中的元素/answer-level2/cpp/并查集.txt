## 问题描述
给你一个字符串 `s`，以及该字符串中的一些「索引对」数组 `pairs`，其中 `pairs[i] = [a, b]` 表示字符串中的两个索引（编号从 0 开始）。

你可以 任意多次交换 在 `pairs` 中任意一对索引处的字符。

返回在经过若干次交换后，`s` 可以变成的按字典序最小的字符串。
![](https://pic.leetcode-cn.com/300767518a5d4864e0981f11a7dfe44a2a894be4fac42985528ec175eddb9115.png)

[交换字符串中的元素](https://leetcode-cn.com/problems/smallest-string-with-swaps/ "交换字符串中的元素")

## 解决方法
### 并查集
关于并查集，[这篇文章](https://blog.csdn.net/qq_41593380/article/details/81146850 "这篇文章")写的不错

- 先将能相互交换的元素找到，相当于分几个集合。

- 遍历s，查看当前元素s[i]隶属于那个集合，将集合中最小的元素取出，添加到返回值中。

举个例子：

s="dcab" , pairs = [[0,3],[1,2]],现将元素扎堆分类为[3,2,2,3]

```cpp
/*
第一步：发现d隶属于3，而属于集合3的最小元素是b，所以res="b",将b抛出集合

第二部：发现c隶属于2，而属于集合2的最小元素是a，所以res="ba",将a抛出集合

第三步：发现a隶属于2，而属于集合2的最小元素是c，所以res="bac",将c抛出集合

第四步：发现b隶属于3，而属于集合3的最小元素是d，所以res="bacd",将d抛出集合
*/
```

```cpp
class Solution {
public:
    int pre[100001];
    int find(int root){
        int son, tmp;
        son = root;
		//找祖先节点
        while(root != pre[root])
            root = pre[root];
        while(son != root)//路径压缩
        {
            tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }
        return root;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size=s.size();
        for(int i=0;i<size;i++)pre[i]=i;
        for(auto item:pairs){
            pre[find(item[0])]=find(item[1]);
        }
        vector<vector<char>>v(size);
		//扎堆分类
        for(int i=0;i<size;i++){
            v[find(i)].push_back(s[i]);
        }
        string res;
		//集合中元素逆序排序
        for(int i=0;i<size;i++){
            sort(v[i].rbegin(),v[i].rend());
        }
		//构造返回值
        for(int i=0;i<size;i++){
            res+=v[pre[i]].back();
            v[pre[i]].pop_back();
        }
        return res;
    }
};
```

my site:[https://liyiping.cn](https://liyiping.cn)