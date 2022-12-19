### 解题思路
![image.png](https://pic.leetcode-cn.com/e2dab6a3cedd7758355ce8a086fbaa737b37bd15d66454dd123b083272980a8b-image.png)
首先，我们正序遍历一次数组，然后在逆序遍历一次数组，然后计算总和就好了。
正序遍历的时候，如果前面位置的分数小过后面的分数（索引值低的为前面），那么后面的位置应该分发的糖果就是前面的+1的和。
逆序的时候，和正序差不多，如果后面位置的分数小过前面的分数（索引值低的为前面），那么前面位置应该分发的糖果就是后面的+1的和；
但是逆序时有一点很关键的时，就是由于我们已经正序遍历过一次数组了，所以前面位置应该分发的糖果会很高，或者很低；
那么这时候我们要判断，后面位置应该分发的糖果数+1 会不会比 前面位置正序遍历过一遍后本来要分发的糖果数还高，如果不会的话，那么就不做任何操作。
反之如果会的话，那就修改前面位置的分发的糖果数。

如果看不懂的话，可以看代码，代码不长
写的不好，还请多多指教。
### 代码

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int res=ratings.size();
        vector<int> tmp(res,0);
        for(int i=1;i<res;i++)
            if(ratings[i]>ratings[i-1]) 
                tmp[i]=tmp[i-1]+1;
        for(int i=res-1;i>0;i--)
            if(ratings[i-1]>ratings[i] && tmp[i-1]<tmp[i]+1) //比正序多了一个判断
                tmp[i-1]=tmp[i]+1;
        for(int i=0;i<ratings.size();i++)
            res+=tmp[i];
        return res;
    }
};
```