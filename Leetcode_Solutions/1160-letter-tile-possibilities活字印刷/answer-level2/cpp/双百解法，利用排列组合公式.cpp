### 解题思路
![1.png](https://pic.leetcode-cn.com/97aaebf76ed67dfe879298fc8bbeb1b28123e447019f84499828f1bef950d842-1.png)

题目求不同排列的字符串的数量，很直观的一个做法就是把所有字符串数量计算出来然后计算大小。
这里其实我们并不需要那么麻烦。还记得高中学过的排列组合公式吗？

对于 m 个 A，n 个 B进行排列时(此处我们记A[i]为 i 的阶乘):
其总数应为
#   A[m+n]/(A[m]*A[n]);

### 代码

```cpp
class Solution {
public:
    int ans;
    int A[8] = {1,1,2,6,24,120,720,5040};//数据量不大，所以我们可以先记下A[i]的值
    //dfs的思路是我们选择每个字符在排列时可能出现的次数，通过tmp记录重复排列的数量，
    //len记录 本次字符串的总长度，那么 这个排列的值就为 A[len]/tmp
    void dfs(vector<int>& arr, int index,int len, int tmp){ 
        if(index == arr.size())
        {
            ans += A[len]/tmp;
            return ;
        }
        for(int i = 0 ; i <= arr[index]; i++){
            dfs(arr,index+1,len+i,tmp*A[i]);
        }
    }
    // 将字符分类记录其个数，利用排列公式计算个数
    //例如：m个A，n个B 得到其排列为 A(m+n)/A(m)/A(n)
    int numTilePossibilities(string tiles) {
        map<char,int> mp;
        int len = tiles.size(); 
        for(char ch : tiles)
            mp[ch] ++; //通过map 记录 出现字符的值并将其保留到vector 中
        vector<int> arr;
        for(auto it : mp){
            arr.push_back(it.second);
        }
        dfs(arr,0,0,1);
        return ans-1; 
        //最后减一是因为我们求了一次A[0]/tmp,此处tmp为若干个A[0]的乘积
    }
};
```