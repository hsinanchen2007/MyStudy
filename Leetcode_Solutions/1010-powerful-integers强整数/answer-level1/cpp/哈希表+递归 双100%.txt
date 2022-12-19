![1586156428(1).jpg](https://pic.leetcode-cn.com/e700d79b2c3f7161b1ae71253c627a28ffbd53d044542f165521702a9fc696af-1586156428\(1\).jpg)


如可以优化的地方，欢迎提出宝贝意见。

```
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_map<int,int> map1;//用来判断符合当前强整数是否已经出现
        vector<int> vec;//最终结果
        int i=0,j=0;
        exm(x,y,i,j,vec,map1,bound);
        return vec;
    }
    void exm(int x,int y,int i,int j,vector<int>& vec,unordered_map<int,int>& map1,int bound){
        if(!map1[pow(x,i)+pow(y,j)]&&pow(x,i)+pow(y,j)<=bound){
            map1[pow(x,i)+pow(y,j)]+=1;
            vec.push_back(pow(x,i)+pow(y,j));
            exm(x,y,i+1,j,vec,map1,bound);
            exm(x,y,i,j+1,vec,map1,bound);
            exm(x,y,i+1,j+1,vec,map1,bound);
        }

    }
};
```
